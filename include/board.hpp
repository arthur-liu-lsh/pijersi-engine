#ifndef BOARD_HPP
#define BOARD_HPP
#include <piece.hpp>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

namespace PijersiEngine
{
    class Board
    {
    public:
        Board();
        Board(Board &board);
        // ~Board();

        void playManual(vector<int> move);
        vector<int> ponderAlphaBeta(int recursionDepth, bool random);
        vector<int> playAlphaBeta(int recursionDepth = 3, bool random = true);
        vector<int> playMCTS(int seconds = 10, int simulationsPerRollout = 3);
        vector<int> ponderRandom();
        vector<int> playRandom();
        vector<int> ponderMCTS(int seconds, int simulationsPerRollout);
        bool isMoveLegal(vector<int> move);
        int16_t evaluate();
        void setState(uint8_t newState[45]);
        uint8_t *getState();
        void init();

        uint8_t at(int i, int j);
        void print();
        string toString();

        bool checkWin();
        int16_t getForecast();
        uint8_t currentPlayer = 0;

    private:
        uint8_t cells[45];
        int16_t forecast = 0;

        void addPiece(uint8_t piece, int i, int j);

    };

}
#endif