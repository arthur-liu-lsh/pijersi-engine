#include <logic.hpp>
#include <rng.hpp>

#include <iostream>
#include <string>
#include <utility>

using namespace std;

namespace PijersiEngine::Logic
{
    // A bitmask associating a cell index to the indices of its 1-range neighbours
    uint64_t neighbours[45] = {
        194ULL,
        389ULL,
        778ULL,
        1556ULL,
        3112ULL,
        6160ULL,
        8321ULL,
        24899ULL,
        49798ULL,
        99596ULL,
        199192ULL,
        398384ULL,
        264224ULL,
        1589440ULL,
        3187072ULL,
        6374144ULL,
        12748288ULL,
        25496576ULL,
        50468864ULL,
        68165632ULL,
        203972608ULL,
        407945216ULL,
        815890432ULL,
        1631780864ULL,
        3263561728ULL,
        2164523008ULL,
        13020692480ULL,
        26108493824ULL,
        52216987648ULL,
        104433975296ULL,
        208867950592ULL,
        413440933888ULL,
        558412857344ULL,
        1670943604736ULL,
        3341887209472ULL,
        6683774418944ULL,
        13367548837888ULL,
        26735097675776ULL,
        17731772481536ULL,
        1112396529664ULL,
        2774548873216ULL,
        5549097746432ULL,
        11098195492864ULL,
        22196390985728ULL,
        9208409882624ULL
    };

    // A bitmask associating a cell index to the indices of its 2-range neighbours
    uint64_t neighbours2[45] = {
        16388ULL,
        40968ULL,
        81937ULL,
        163874ULL,
        327684ULL,
        131080ULL,
        1048832ULL,
        2621952ULL,
        5243968ULL,
        10487936ULL,
        20975872ULL,
        41943552ULL,
        16778240ULL,
        134250498ULL,
        335609861ULL,
        671227914ULL,
        1342455828ULL,
        2684387368ULL,
        1073807376ULL,
        8592031872ULL,
        21479031104ULL,
        42958586496ULL,
        85917172992ULL,
        171834345984ULL,
        343601583104ULL,
        137447344128ULL,
        1099780079616ULL,
        2749315981312ULL,
        5498699071488ULL,
        10997398142976ULL,
        21990501318656ULL,
        8796630024192ULL,
        17180917760ULL,
        34362359808ULL,
        73019686912ULL,
        146039373824ULL,
        292078747648ULL,
        34401681408ULL,
        68736253952ULL,
        2199157473280ULL,
        4398382055424ULL,
        9346519924736ULL,
        18693039849472ULL,
        2201707610112ULL,
        4399120252928ULL
    };

    string rowLetters = "gfedcba";
    
    string invalidCellStringException = "Invalid character in coordinates string.";
    string invalidMoveStringException = "Invalid move string.";

    // Converts a (i, j) coordinate set to an index
    int coordsToIndex(int i, int j)
    {
        int index;
        if (i % 2 == 0)
        {
            index = 13 * i / 2 + j;
        }
        else
        {
            index = 6 + 13 * (i - 1) / 2 + j;
        }
        return index;
    }

    // Converts an index to a (i, j) coordinate set
    Coords indexToCoords(int index)
    {
        int i = 2 * (index / 13);
        int j = index % 13;
        if (j > 5)
        {
            j -= 6;
            i += 1;
        }
        return Coords(i, j);
    }

    // Converts an index to a line number
    int indexToLine(int index)
    {
        int i = 2 * (index / 13);
        if ((index % 13) > 5)
        {
            i += 1;
        }
        return i;
    }

    // Converts a native index into a "a1" style string
    string indexToString(int index)
    {
        Coords coords = indexToCoords(index);
        string cellString = rowLetters[coords.first] + to_string(coords.second + 1);
        return cellString;
    }

    // Converts a "a1" style string coordinate into an index
    int stringToIndex(string cellString)
    {
        int i, j;
        if (cellString.size() == 2)
        {
            switch (cellString[0])
            {
            case 'a':
                i = 6;
                break;
            case 'b':
                i = 5;
                break;
            case 'c':
                i = 4;
                break;
            case 'd':
                i = 3;
                break;
            case 'e':
                i = 2;
                break;
            case 'f':
                i = 1;
                break;
            case 'g':
                i = 0;
                break;
            default:
                throw invalid_argument(invalidCellStringException);
            }
            switch (cellString[1])
            {
            case '1':
                j = 0;
                break;
            case '2':
                j = 1;
                break;
            case '3':
                j = 2;
                break;
            case '4':
                j = 3;
                break;
            case '5':
                j = 4;
                break;
            case '6':
                j = 5;
                break;
            case '7':
                j = 6;
                break;
            default:
                throw invalid_argument(invalidCellStringException);
            }
        }
        return coordsToIndex(i,j);
    }

    // Convert a native triple-index move into the string (a1-b1=c1 style) format.
    string moveToString(int move[3], uint64_t pieces[18])
    {
        int indexStart = move[0];
        int indexMid = move[1];
        int indexEnd = move[2];

        if (indexStart < 0)
        {
            return string("");
        }

        string moveString = indexToString(indexStart);

        if (indexMid >= 0)
        {
            if (indexMid == indexStart)
            {
                moveString += "-" + indexToString(indexEnd);
            }
            else if (pieces[indexStart] >= 16)
            {
                if (pieces[indexMid] != 0 && (pieces[indexMid] & 2) == (pieces[indexStart] & 2))
                {
                    moveString += "-" + indexToString(indexMid) + "=" + indexToString(indexEnd);
                }
                else
                {
                    moveString += "=" + indexToString(indexMid) + "-" + indexToString(indexEnd);
                }
            }
            else
            {
                moveString += "-" + indexToString(indexMid) + "=" + indexToString(indexEnd);
            }
        }
        else
        {
            if (pieces[indexStart] >= 16)
            {
                moveString += "=" + indexToString(indexEnd);
            }
            else
            {
                moveString += "-" + indexToString(indexEnd);
            }
        }
        return moveString;
    }

    // Converts a string (a1-b1=c1 style) move to the native triple-index format
    vector<int> stringToMove(string moveString, uint64_t pieces[18])
    {
        vector<int> move(3, -1);
        if(moveString.size() == 5)
        {
            move[0] = stringToIndex(moveString.substr(0, 2));
            move[2] = stringToIndex(moveString.substr(3, 2));
            if (moveString[2] == '-')
            {
                if (pieces[move[0]] >= 16 || ((pieces[move[0]] & 2) == (pieces[move[1]] & 2)))
                {
                    move[1] = move[0];
                }
            }
        }
        else if (moveString.size() == 8)
        {
            move[0] = stringToIndex(moveString.substr(0, 2));
            move[1] = stringToIndex(moveString.substr(3, 2));
            move[2] = stringToIndex(moveString.substr(6, 2));
        }
        else
        {
            throw invalid_argument(invalidMoveStringException);
        }
        return move;
    }

    // Subroutine of the perft debug function that is ran by the main perft() function
    uint64_t _perftIter(int recursionDepth, uint64_t pieces[18], uint8_t currentPlayer)
    {
        if (isWin(pieces))
        {
            return 0ULL;
        }
        // Get a vector of all the available moves for the current player
        vector<int> moves = availablePlayerMoves(currentPlayer, pieces);
        size_t nMoves = moves.size() / 3;
        if (recursionDepth == 1)
        {
            return nMoves;
        }

        uint64_t sum = 0ULL;

        uint64_t newCells[18];
        for (size_t k = 0; k < nMoves; k++)
        {
            setState(newCells, pieces);
            playManual(moves.data() + 3 * k, newCells);
            sum += _perftIter(recursionDepth - 1, newCells, 1 - currentPlayer);
        }
        return sum;
    }

    // Perft debug function to measure the number of leaf nodes (possible moves) at a given depth
    uint64_t perft(int recursionDepth, uint64_t pieces[18], uint8_t currentPlayer)
    {
        if (recursionDepth == 0)
        {
            return 1ULL;
        }
        else if (isWin(pieces))
        {
            return 0ULL;
        }
        else if (recursionDepth == 1)
        {
            return _perftIter(1, pieces, currentPlayer);
        }
        else
        {
            // Get a vector of all the available moves for the current player
            vector<int> moves = availablePlayerMoves(currentPlayer, pieces);
            size_t nMoves = moves.size() / 3;

            uint64_t sum = 0ULL;
#pragma omp parallel for schedule(dynamic) reduction(+ \
                                                     : sum)
            for (size_t k = 0; k < nMoves; k++)
            {
                uint64_t newCells[18];
                setState(newCells, pieces);
                playManual(moves.data() + 3 * k, newCells);
                sum += _perftIter(recursionDepth - 1, newCells, 1 - currentPlayer);
            }
            return sum;
        }
    }

    vector<string> perftSplit(int recursionDepth, uint64_t pieces[18], uint8_t currentPlayer)
    {
        vector<string> results;
        if (recursionDepth == 0 || isWin(pieces))
        {
            return results;
        }

        results.reserve(256);

        // Get a vector of all the available moves for the current player
        vector<int> moves = availablePlayerMoves(currentPlayer, pieces);
        size_t nMoves = moves.size() / 3;

        // Converts all those moves to string format
        for (size_t k = 0; k < nMoves; k++)
        {
            results.push_back(moveToString(moves.data() + 3 * k, pieces));
        }

        if (recursionDepth == 1)
        {
            return results;
        }
        else
        {

            // Add the number of leaf nodes associated to the corresponding move
            #pragma omp parallel for schedule(dynamic)
            for (size_t k = 0; k < nMoves; k++)
            {
                uint64_t newCells[18];
                setState(newCells, pieces);
                playManual(moves.data() + 3 * k, newCells);
                results[k] += ": " + to_string(_perftIter(recursionDepth - 1, newCells, 1 - currentPlayer));
            }
        }
        return results;
    }

    // Copy the data from origin to target
    void setState(uint64_t target[18], const uint64_t origin[18])
    {
        copy(origin, origin+18, target);
    }

    // Plays the selected move
    void play(int indexStart, int indexMid, int indexEnd, uint64_t pieces[18])
    {
        if (indexStart < 0)
        {
            return;
        }
        uint8_t movingPiece = pieces[indexStart];
        if (movingPiece != 0)
        {
            // If there is no intermediate move
            if (indexMid < 0)
            {
                // Simple move
                move(indexStart, indexEnd, pieces);
            }
            // There is an intermediate move
            else
            {
                uint8_t midPiece = pieces[indexMid];
                uint8_t endPiece = pieces[indexEnd];
                // The piece at the mid coordinates is an ally : stack and move
                if (midPiece != 0 && (midPiece & 2) == (movingPiece & 2) && (indexMid != indexStart))
                {
                    stack(indexStart, indexMid, pieces);
                    move(indexMid, indexEnd, pieces);
                }
                // The piece at the end coordinates is an ally : move and stack
                else if (endPiece != 0 && (endPiece & 2) == (movingPiece & 2))
                {
                    move(indexStart, indexMid, pieces);
                    stack(indexMid, indexEnd, pieces);
                }
                // The end coordinates contain an enemy or no piece : move and unstack
                else
                {
                    move(indexStart, indexMid, pieces);
                    unstack(indexMid, indexEnd, pieces);
                }
            }
        }
    }

    void playManual(int move[3], uint64_t pieces[18])
    {
        play(move[0], move[1], move[2], pieces);
    }

    // Generates a random move
    vector<int> ponderRandom(uint64_t pieces[18], uint8_t currentPlayer)
    {
        // Get a vector of all the available moves for the current player
        vector<int> moves = availablePlayerMoves(currentPlayer, pieces);

        if (moves.size() > 0)
        {
            uniform_int_distribution<int> intDistribution(0, moves.size() / 6 - 1);

            int index = intDistribution(RNG::gen);

            vector<int>::const_iterator first = moves.begin() + 6 * index;
            vector<int>::const_iterator last = moves.begin() + 6 * (index + 1);
            vector<int> move(first, last);
            return move;
        }
        return vector<int>({-1, -1, -1, -1, -1, -1});
    }

    // Plays a random move
    vector<int> playRandom(uint64_t pieces[18], uint8_t currentPlayer)
    {
        vector<int> move = ponderRandom(pieces, currentPlayer);
        // Apply move
        playManual(move.data(), pieces);

        return move;
    }

    // Returns true if the board is in a winning position
    bool isWin(const uint64_t pieces[18])
    {
        return (pieces[8] & 63) != 0 || (pieces[17] & 34634616274944ULL) != 0;
    }

    // Returns the list of possible moves for a specific piece
    vector<int> availablePieceMoves(int indexStart, uint64_t pieces[18])
    {
        uint8_t movingPiece = pieces[indexStart];

        vector<int> moves = vector<int>();
        moves.reserve(128);

        // // If the piece is not a stack
        // if (movingPiece < 16)
        // {
        //     // 1-range first action
        //     for (int indexMid : neighbours[indexStart])
        //     {
        //         // stack, [1/2-range move] optional
        //         if (isStackValid(movingPiece, indexMid, pieces))
        //         {
        //             // stack, 2-range move
        //             for (int indexEnd : neighbours2[indexMid])
        //             {
        //                 if (isMove2Valid(movingPiece, indexMid, indexEnd, pieces) || ((indexStart == (indexMid + indexEnd) / 2) && isMoveValid(movingPiece, indexEnd, pieces)))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }

        //             // stack, 0/1-range move
        //             for (int indexEnd : neighbours[indexMid])
        //             {
        //                 if (isMoveValid(movingPiece, indexEnd, pieces) || (indexStart == indexEnd))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }

        //             // stack only
        //             moves.insert(moves.end(), {indexStart, indexStart, indexMid});
        //         }
        //         // 1-range move
        //         if (isMoveValid(movingPiece, indexMid, pieces))
        //         {
        //             moves.insert(moves.end(), {indexStart, -1, indexMid});
        //         }
        //     }
        // }
        // else
        // {
        //     // 2 range first action
        //     for (int indexMid : neighbours2[indexStart])
        //     {
        //         if (isMove2Valid(movingPiece, indexStart, indexMid, pieces))
        //         {
        //             // 2-range move, stack or unstack
        //             for (int indexEnd : neighbours[indexMid])
        //             {
        //                 // 2-range move, unstack
        //                 if (isUnstackValid(movingPiece, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }

        //                 // 2-range move, stack
        //                 if (isStackValid(movingPiece, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }

        //             // 2-range move
        //             moves.insert(moves.end(), {indexStart, -1, indexMid});
        //         }
        //     }
        //     // 1-range first action
        //     for (int indexMid : neighbours[indexStart])
        //     {

        //         // 1-range move, [stack or unstack] optional
        //         if (isMoveValid(movingPiece, indexMid, pieces))
        //         {

        //             // 1-range move, stack or unstack
        //             for (int indexEnd : neighbours[indexMid])
        //             {
        //                 // 1-range move, unstack
        //                 if (isUnstackValid(movingPiece, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }

        //                 // 1-range move, stack
        //                 if (isStackValid(movingPiece, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }
        //             // 1-range move, unstack on starting position
        //             moves.insert(moves.end(), {indexStart, indexMid, indexStart});

        //             // 1-range move
        //             moves.insert(moves.end(), {indexStart, -1, indexMid});
        //         }
        //         // stack, [1/2-range move] optional
        //         if (isStackValid(movingPiece, indexMid, pieces))
        //         {
        //             // stack, 2-range move
        //             for (int indexEnd : neighbours2[indexMid])
        //             {
        //                 if (isMove2Valid(movingPiece, indexMid, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }

        //             // stack, 1-range move
        //             for (int indexEnd : neighbours[indexMid])
        //             {
        //                 if (isMoveValid(movingPiece, indexEnd, pieces))
        //                 {
        //                     moves.insert(moves.end(), {indexStart, indexMid, indexEnd});
        //                 }
        //             }

        //             // stack only
        //             moves.insert(moves.end(), {indexStart, indexStart, indexMid});
        //         }

        //         // unstack
        //         if (isUnstackValid(movingPiece, indexMid, pieces))
        //         {
        //             // unstack only
        //             moves.insert(moves.end(), {indexStart, indexStart, indexMid});
        //         }
        //     }
        // }

        return moves;
    }

    // Returns the list of possible moves for a player
    vector<int> availablePlayerMoves(uint8_t player, uint64_t pieces[18])
    {
        vector<int> moves = vector<int>();
        // Reserve space in vector for optimization purposes
        moves.reserve(1024);
        // Calculate possible moves
        for (int index = 0; index < 45; index++)
        {
            if (pieces[index] != 0)
            {
                // Choose pieces of the current player's colour
                if ((pieces[index] & 2) == (player << 1))
                {
                    vector<int> pieceMoves = availablePieceMoves(index, pieces);
                    moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
                }
            }
        }
        return moves;
    }

    // Returns whether a source piece can capture a target piece
    bool canTake(uint8_t source, uint8_t target)
    {
        uint8_t sourceType = source & 12;
        uint8_t targetType = target & 12;
        // Scissors > Paper, Paper > Rock, Rock > Scissors
        if ((sourceType == 0 && targetType == 4) || (sourceType == 4 && targetType == 8) || (sourceType == 8 && targetType == 0))
        {
            return true;
        }
        return false;
    }

    // Applies a move between chosen coordinates
    void move(int indexStart, int indexEnd, uint64_t pieces[18])
    {
        // Do nothing if start and end coordinate are identical
        if (indexStart != indexEnd)
        {
            // Move the piece to the target cell
            pieces[indexEnd] = pieces[indexStart];

            // Set the starting cell as empty
            pieces[indexStart] = 0;
        }
    }

    // Applies a stack between chosen coordinates
    void stack(int indexStart, int indexEnd, uint64_t pieces[18])
    {
        uint8_t movingPiece = pieces[indexStart];
        uint8_t endPiece = pieces[indexEnd];

        // If the moving piece is already on top of a stack, leave the bottom piece in the starting cell
        pieces[indexStart] = (movingPiece >> 4);

        // Move the top piece to the target cell and set its new bottom piece
        pieces[indexEnd] = (movingPiece & 15) + (endPiece << 4);
    }

    // Applies an unstack between chosen coordinates
    void unstack(int indexStart, int indexEnd, uint64_t pieces[18])
    {
        uint8_t movingPiece = pieces[indexStart];

        // Leave the bottom piece in the starting cell
        pieces[indexStart] = (movingPiece >> 4);
        // Remove the bottom piece from the moving piece
        // Move the top piece to the target cell
        // Will overwrite the eaten piece if there is one
        pieces[indexEnd] = (movingPiece & 15);
    }

    // Returns whether a certain 1-range move is possible
    bool isMoveValid(uint8_t movingPiece, int indexEnd, uint64_t pieces[18])
    {
        if (pieces[indexEnd] != 0)
        {
            // If the end piece and the moving piece are the same colour
            if ((pieces[indexEnd] & 2) == (movingPiece & 2))
            {
                return false;
            }
            if (!canTake(movingPiece, pieces[indexEnd]))
            {
                return false;
            }
        }
        return true;
    }

    // Returns whether a certain 2-range move is possible
    bool isMove2Valid(uint8_t movingPiece, int indexStart, int indexEnd, uint64_t pieces[18])
    {
        // If there is a piece blocking the move (cell between the start and end positions)
        if (pieces[(indexEnd + indexStart) / 2] != 0)
        {
            return false;
        }
        if (pieces[indexEnd] != 0)
        {
            // If the end piece and the moving piece are the same colour
            if ((pieces[indexEnd] & 2) == (movingPiece & 2))
            {
                return false;
            }
            if (!canTake(movingPiece, pieces[indexEnd]))
            {
                return false;
            }
        }
        return true;
    }

    // Returns whether a certain stack action is possible
    bool isStackValid(uint8_t movingPiece, int indexEnd, const uint64_t pieces[18])
    {
        // If the end cell is not empty
        // If the target piece and the moving piece are the same colour
        // If the end piece is not a stack
        if ((pieces[indexEnd] != 0) && ((pieces[indexEnd] & 2) == (movingPiece & 2)) && (pieces[indexEnd] < 16))
        {
            // If the upper piece is Wise and the target piece is not Wise
            if ((movingPiece & 12) == 12 && (pieces[indexEnd] & 12) != 12)
            {
                return false;
            }
            return true;
        }
        return false;
    }

    // Returns whether a certain unstack action is possible
    bool isUnstackValid(uint8_t movingPiece, int indexEnd, uint64_t pieces[18])
    {
        if (pieces[indexEnd] != 0)
        {
            // If the pieces are the same colour
            if ((pieces[indexEnd] & 2) == (movingPiece & 2))
            {
                return false;
            }
            if (!canTake(movingPiece, pieces[indexEnd]))
            {
                return false;
            }
        }
        return true;
    }

}