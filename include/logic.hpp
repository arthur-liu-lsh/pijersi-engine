#ifndef LOGIC_HPP
#define LOGIC_HPP
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

using namespace std;

namespace PijersiEngine::Logic
{
    using Coords = pair<int,int>;

    int coordsToIndex(int i, int j);
    Coords indexToCoords(int index);
    int indexToLine(int index);
    string indexToString(int index);
    int stringToIndex(string cellString);
    string moveToString(int move[3], uint64_t pieces[18]);
    vector<int> stringToMove(string moveString, uint64_t pieces[18]);
    uint64_t perft(int recursionDepth, uint64_t pieces[18], uint8_t currentPlayer);
    vector<string> perftSplit(int recursionDepth, uint64_t pieces[18], uint8_t currentPlayer);
    void setState(uint64_t target[18], const uint64_t origin[18]);
    void play(int indexStart, int indexMid, int indexEnd, uint64_t pieces[18]);
    void playManual(int move[3], uint64_t *pieces);
    vector<int> ponderRandom(uint64_t pieces[18], uint8_t currentPlayer);
    vector<int> playRandom(uint64_t pieces[18], uint8_t currentPlayer);
    bool isWin(const uint64_t pieces[18]);
    vector<int> availablePieceMoves(int indexStart, uint64_t pieces[18]);
    vector<int> availablePlayerMoves(uint8_t player, uint64_t pieces[18]);
    bool canTake(uint8_t source, uint8_t target);
    void move(int indexStart, int indexEnd, uint64_t pieces[18]);
    void stack(int indexStart, int indexEnd, uint64_t pieces[18]);
    void unstack(int indexStart, int indexEnd, uint64_t pieces[18]);
    bool isMoveValid(uint8_t movingPiece, int indexEnd, uint64_t pieces[18]);
    bool isMove2Valid(uint8_t movingPiece, int indexStart, int indexEnd, uint64_t pieces[18]);
    bool isStackValid(uint8_t movingPiece, int indexEnd, const uint64_t pieces[18]);
    bool isUnstackValid(uint8_t movingPiece, int indexEnd, uint64_t pieces[18]);
}

#endif