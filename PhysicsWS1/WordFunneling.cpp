#include "WordFunneling.h"

bool WordFunneling::WordFunnel(std::string inString,std::string checkString)
{
    for (int i = 0; i < inString.size(); i++) {
        std::string modified = inString;
        modified.erase(i,1);
        if (modified == checkString) return true;

    }
    return false;
}bool WordFunneling::WordFunnelAllOccurrences(std::string inString,std::string checkString)
{
    for (int i = 0; i < inString.size(); i++) {
        std::string modified = inString;
        modified.erase(std::remove(modified.begin(), modified.end(), modified[i]),modified.end());
        if (modified == checkString) return true;

    }
    return false;
}
