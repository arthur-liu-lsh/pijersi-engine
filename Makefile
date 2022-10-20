INCLUDE=-Iinclude
HEADERS=include/alphabeta.hpp include/board.hpp include/logic.hpp include/mcts.hpp include/nn.hpp include/piece.hpp include/rng.hpp
FLAGS=-flto -O3 -fopenmp
SRC=src/alphabeta.cpp src/board.cpp src/logic.cpp src/mcts.cpp src/nn.cpp src/rng.cpp
OBJ=src/alphabeta.o src/board.o src/logic.o src/mcts.o src/nn.o src/rng.o
CSHARP_SRC=src/wrap/pijersi_engine_csharp.cpp
CSHARP_OBJ=src/wrap/pijersi_engine_csharp.o
CSHARP_DLL=wrap_csharp/PijersiCore.dll

all: csharp

csharp: $(CSHARP_DLL)

$(CSHARP_SRC): pijersi_engine.i $(HEADERS)
	@if not exist "wrap_csharp" mkdir wrap_csharp
	@if not exist "src\wrap" mkdir src\wrap
	@swig -csharp -c++ $(INCLUDE) -namespace PijersiEngine -outdir wrap_csharp -o $(CSHARP_SRC) pijersi_engine.i

$(CSHARP_OBJ): $(CSHARP_SRC) $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) $(CSHARP_SRC) -o $(CSHARP_OBJ)

$(CSHARP_DLL): $(OBJ) $(CSHARP_OBJ)
	@if not exist "wrap_csharp" mkdir wrap_csharp
	@g++ $(FLAGS) -shared $(INCLUDE) $(OBJ) $(CSHARP_OBJ) -o $(CSHARP_DLL)

src/alphabeta.o: src/alphabeta.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/alphabeta.cpp -o src/alphabeta.o

src/board.o: src/board.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/board.cpp -o src/board.o

src/logic.o: src/logic.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/logic.cpp -o src/logic.o

src/mcts.o: src/mcts.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/mcts.cpp -o src/mcts.o

src/nn.o: src/nn.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/nn.cpp -o src/nn.o

src/rng.o: src/rng.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/rng.cpp -o src/rng.o

debug: build/debug.exe

build/debug.exe: $(SRC) src/debug.cpp
	@if not exist "build" mkdir build
	@g++ -ggdb $(FLAGS) $(INCLUDE) $(SRC) src/debug.cpp -o build/debug.exe

train: build/train.exe

src/train.o: $(SRC) src/train.cpp $(HEADERS)
	@g++ $(FLAGS) -c $(INCLUDE) src/train.cpp -o src/train.o

build/train.exe: $(OBJ) src/train.o
	@if not exist "build" mkdir build
	@g++ $(FLAGS) $(INCLUDE) $(OBJ) src/train.o -o build/train.exe

clean:
	@del /Q /F /S wrap_csharp\*
	@if exist "src\wrap" rmdir /Q /s "src\wrap"
	@del /Q /F /S "src\*.o"
	@if exist "build" rmdir /Q /s "build"