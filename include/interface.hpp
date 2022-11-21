#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <string>

#include <board.hpp>

using namespace std;

namespace PijersiEngine::Interface
{

    class EngineInterface
    {
    public:
        string sendCommand(string command);

    private:
        Board board;
    };
}

#endif