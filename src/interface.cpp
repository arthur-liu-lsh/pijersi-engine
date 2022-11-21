#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

#include <board.hpp>
#include <interface.hpp>
#include <logic.hpp>

namespace PijersiEngine::Interface
{
    // The two following functions come from https://stackoverflow.com/questions/10058606/splitting-a-string-by-a-character
    vector<string> splitstring(string input, char separator = ' ')
    {
        istringstream test(input);
        std::string segment;
        std::vector<std::string> seglist;

        while (getline(test, segment, separator))
        {
            segment.erase(remove(segment.begin(), segment.end(), '\n'), segment.cend());
            segment.erase(remove(segment.begin(), segment.end(), ' '), segment.cend());
            segment.erase(remove(segment.begin(), segment.end(), '\r'), segment.cend());
            seglist.push_back(segment);
        }
        return seglist;
    }

    string upi()
    {
        string response = "";
        response += "info name Natural Selection\n";
        response += "info author Arthur Liu\n";
        response += "upiok";
        return response;
    }

    string upinewgame()
    {
        return "";
    }

    string position(string psnString)
    {
        return "";
    }

    string EngineInterface::sendCommand(string input)
    {
        vector<string> words = splitstring(input);
        string command = "";
        string param1 = "";
        string param2 = "";
        if (words.size() > 0)
        {
            command = words[0];
            if (words.size() > 1)
            {
                param1 = words[1];
                if (words.size() > 2)
                {
                    param2 = words[2];
                }
            }
        }

        if (command == "init" || command == "i")
        {
            board.init();
            return "Board initialized";
        }
        else if (command == "print" || command == "pr")
        {
            return board.toString();
        }
        else if (command == "play" || command == "pl")
        {
            try
            {
                if (param1.size() == 0)
                {
                    throw invalid_argument("Empty move.");
                }
                vector<int> move = Logic::stringToMove(param1, board.getState());
                if (!board.isMoveLegal(move))
                {
                    throw invalid_argument("Illegal move.");
                }
                board.playManual(move);
            }
            catch (invalid_argument& e)
            {
                return "Error: " + string(e.what());
            }
        }
        else if (command == "auto" || command == "a")
        {
            {
            if (param1 == "ab")
                try
                {
                    int recursionDepth = stoi(param2);
                    if (recursionDepth > 0)
                    {
                        vector<int> move = board.ponderAlphaBeta(recursionDepth, true);
                        string moveString = Logic::moveToString(move.data(), board.getState());
                        board.playManual(move);
                        return moveString;
                    }
                    else
                    {
                        throw invalid_argument("The recursion depth must be 1 or more.");
                    }
                }
                catch (invalid_argument& e)
                {
                    return "Error: " + string(e.what());
                }
            }
        }
        else if (command == "quit" || command == "q")
        {
            exit(0);
        }
        // if (command == "upi")
        // {
        //     return upi();
        // }
        // else if (command == "upinewgame")
        // {
        //     board.init();
        // }
        // else if (command == "go")
        // {
        //     if (param1 == "depth")
        //     {
        //         try
        //         {
        //             int recursionDepth = stoi(param2);
        //             if (recursionDepth > 0)
        //             {
        //                 vector<int> move = board.ponderAlphaBeta(recursionDepth, true);
        //                 string moveString = Logic::moveToString(move.data(), board.getState());
        //                 board.playManual(move);
        //                 return "bestmove " + moveString;
        //             }
        //             else
        //             {
        //                 throw invalid_argument("The recursion depth must be 1 or more.");
        //             }
        //         }
        //         catch (invalid_argument& e)
        //         {
        //             return "Invalid depth";
        //         }
        //     }
        // }
        // else if (command == "quit")
        // {
        //     exit(0);
        // }
        return "";
    }
}