#include <cfloat>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

#include <alphabeta.hpp>
#include <board.hpp>
#include <logic.hpp>
#include <mcts.hpp>
#include <rng.hpp>

using namespace std;

namespace PijersiEngine
{

    // Board constructor
    Board::Board()
    {
        for (int k = 0; k < 18; k++)
        {
            pieces[k] = 0ULL;
        }
    }

    // Board copy constructor
    Board::Board(Board &board)
    {
        setState(board.pieces);
        currentPlayer = board.currentPlayer;
    }

    // Plays a move and returns it
    vector<int> Board::playAlphaBeta(int recursionDepth, bool random)
    {
        // Calculate move
        vector<int> move = ponderAlphaBeta(recursionDepth, random);
        // Apply move
        playManual(move);
        return move;
    }

    // vector<int> Board::ponderAlphaBeta(int recursionDepth, bool random)
    // {
    //     return AlphaBeta::ponderAlphaBeta(recursionDepth, random, cells, currentPlayer);
    // }

    // Chooses a random move
    vector<int> Board::ponderRandom()
    {
        return Logic::ponderRandom(pieces, currentPlayer);
    }

    // Plays a random move and returns it
    vector<int> Board::playRandom()
    {
        return Logic::playRandom(pieces, currentPlayer);
    }

    bool Board::isMoveLegal(vector<int> move)
    {
        if (pieces[move[0]] == 0)
        {
            return false;
        }
        if ((pieces[move[0]] & 2) != currentPlayer << 1)
        {
            return false;
        }
        vector<int> moves = Logic::availablePieceMoves(move[0], pieces);
        size_t nMoves = moves.size() / 3;
        for (size_t k = 0; k < nMoves; k++)
        {
            bool legal = true;
            for (int m = 0; m < 3; m++)
            {
                if (moves[k * 3 + m] != move[m])
                {
                    legal = false;
                }
            }
            if (legal)
            {
                return true;
            }
        }
        return false;
    }

    void Board::playManual(vector<int> move)
    {
        Logic::play(move[0], move[1], move[2], pieces);
        // Set current player to the other colour.
        currentPlayer = 1 - currentPlayer;
    }

    uint8_t Board::at(int i, int j)
    {
        return pieces[Logic::coordsToIndex(i, j)];
    }

    // int16_t Board::evaluate()
    // {
    //     return AlphaBeta::evaluatePosition(pieces);
    // }

    // Adds a piece to the designated coordinates
    void Board::addPiece(PieceColour colour, PieceType type, bool bottom, int i, int j)
    {
        int n = (colour == White) ? 0 : 1;
        int m = -1;
        int o = bottom ? 1 : 0;
        switch (type)
        {
        case Scissors:
            m = 0;
            break;
        case Paper:
            m = 1;
            break;
        case Rock:
            m = 2;
            break;
        case Wise:
            m = 3;
            break;
        }
        pieces[8*n + m + 4 * o] |= (1ULL << Logic::coordsToIndex(i,j));
        if (!bottom)
        {
            pieces[16 + n] |= (1ULL << Logic::coordsToIndex(i,j));
        }
    }

    // Sets the board to a chosen state
    void Board::setState(uint64_t newState[18])
    {
        Logic::setState(pieces, newState);
    }

    uint64_t *Board::getState()
    {
        return pieces;
    }

    // Initializes the board to the starting position
    void Board::init()
    {
        // Reset board
        for (int k = 0; k < 18; k++)
        {
            pieces[k] = 0ULL;
        }

        // Black pieces
        addPiece(Black, Scissors, false, 0, 0);
        addPiece(Black, Paper, false, 0, 1);
        addPiece(Black, Rock, false, 0, 2);
        addPiece(Black, Scissors, false, 0, 3);
        addPiece(Black, Paper, false, 0, 4);
        addPiece(Black, Rock, false, 0, 5);
        addPiece(Black, Paper, false, 1, 0);
        addPiece(Black, Rock, false, 1, 1);
        addPiece(Black, Scissors, false, 1, 2);
        addPiece(Black, Wise, false, 1, 3);
        addPiece(Black, Wise, true, 1, 3);
        addPiece(Black, Rock, false, 1, 4);
        addPiece(Black, Scissors, false, 1, 5);
        addPiece(Black, Paper, false, 1, 6);

        // White pieces
        addPiece(White, Paper, false, 5, 0);
        addPiece(White, Scissors, false, 5, 1);
        addPiece(White, Rock, false, 5, 2);
        addPiece(White, Wise, false, 5, 3);
        addPiece(White, Wise, true, 5, 3);
        addPiece(White, Scissors, false, 5, 4);
        addPiece(White, Rock, false, 5, 5);
        addPiece(White, Paper, false, 5, 6);
        addPiece(White, Rock, false, 6, 0);
        addPiece(White, Paper, false, 6, 1);
        addPiece(White, Scissors, false, 6, 2);
        addPiece(White, Rock, false, 6, 3);
        addPiece(White, Paper, false, 6, 4);
        addPiece(White, Scissors, false, 6, 5);

        // Set active player to White
        currentPlayer = 0;
    }

    string pieceLetters = "SPRWsprw";

    char _indexToChar(uint64_t pieces[18], int index, bool bottom)
    {
        char output = ' ';
        int offset = bottom ? 4 : 0;
        uint64_t mask = 1ULL << index;
        for (int k = 0; k < 4; k++)
        {
            if ((pieces[k + offset] & mask) != 0)
            {
                output = pieceLetters[k];
                return output;
            }
        }
        
        for (int k = 0; k < 4; k++)
        {
            if ((pieces[8 + k + offset] & mask) != 0)
            {
                output = pieceLetters[4 + k];
                return output;
            }
        }
        return output;
    }

    // Prints the board
    // Used for debug purposes
    void Board::print()
    {
        cout << toString();
    }

    // Returns the state of the board in string format
    // Used for debug purposes
    string Board::toString()
    {
        string output = "";
        for (int i = 0; i < 7; i++)
        {
            if (i % 2 == 0)
            {
                output += ' ';
                for (int j = 0; j < 6; j++)
                {
                    int index = Logic::coordsToIndex(i, j);
                    char char1 = _indexToChar(pieces, index, false);
                    char char2 = _indexToChar(pieces, index, true);
                    output += char1;
                    output += char2;
                }
                output += '\n';
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    int index = Logic::coordsToIndex(i, j);
                    char char1 = _indexToChar(pieces, index, false);
                    char char2 = _indexToChar(pieces, index, true);
                    output += char1;
                    output += char2;
                }
                output += '\n';
            }
        }
        return output;
    }

    // Returns true if the board is in a winning position
    bool Board::checkWin()
    {
        return Logic::isWin(pieces);
    }

    int16_t Board::getForecast()
    {
        return forecast;
    }

    // vector<int> Board::ponderMCTS(int seconds, int simulationsPerRollout)
    // {
    //     return MCTS::ponderMCTS(seconds, simulationsPerRollout, pieces, currentPlayer);
    // }

    // Plays a move and returns it
    vector<int> Board::playMCTS(int seconds, int simulationsPerRollout)
    {
        // Calculate move
        vector<int> move = ponderMCTS(seconds, simulationsPerRollout);
        // Apply move
        playManual(move);
        return move;
    }

}
