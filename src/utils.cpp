#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

#include <logic.hpp>
#include <utils.hpp>

using std::string;
using std::vector;

namespace PijersiEngine::Utils
{
    vector<string> split(string str, string token){
        vector<string>result;
        while(str.size()){
            size_t index = str.find(token);
            if(index!=string::npos){
                result.push_back(str.substr(0,index));
                str = str.substr(index+token.size());
                if(str.size()==0)result.push_back(str);
            }else{
                result.push_back(str);
                str = "";
            }
        }
        return result;
    }

    string strip(string str)
    {
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
        return str;
    }

    void sortPrincipalVariation(vector<uint32_t>& moves, uint32_t principalVariation)
    {
        bool sorted = false;
        size_t index = 0;
        while (!sorted && index < moves.size())
        {
            if ((moves[index] & NULL_MOVE) == (principalVariation & NULL_MOVE))
            {
                uint32_t temp = moves[0];
                moves[0] = moves[index];
                moves[index] = temp;
                sorted = true;
            }
            index++;
        }
    }

}