#include <string>
#include "../include/util.h"

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";
 
string ltrim(string s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string rtrim(string s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim(string s) {
    return rtrim(ltrim(s));
}