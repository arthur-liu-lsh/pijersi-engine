@echo off
if not exist "build" mkdir build
cd src
g++ -c -O3 -fopenmp -I../include board.cpp piece.cpp pijersi_engine_wrap.cxx
g++ -fopenmp -shared -I../include board.o piece.o pijersi_engine_wrap.o -o ../build/PijersiCore.dll