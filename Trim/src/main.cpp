#include <iostream>
#include <cctype>
#include <algorithm> 
#include <functional> 
#include <locale>
#include <string.h>

using namespace std;

//Method 1 char array
char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

/*char *rtrim(char *s)
{
    char* back = s + strlen(s) - 1;
    while(isspace(*back)) back--;
    *(back+1) = '\0';
    return s;
}*/

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

//Method 2 string
/*string WHITESPACE = " \t\n\r\f\v";

inline string& rtrim(string& s)
{
    s.erase(s.find_last_not_of(WHITESPACE) + 1);
    return s;
}

inline string& ltrim(string& s)
{
    s.erase(0, s.find_first_not_of(WHITESPACE));
    return s;
}

inline string& trim(string& s)
{
    return ltrim(rtrim(s));
}*/

//Method 3 string
/*string& ltrim(string &s)
{
    auto it = find_if(s.begin(), s.end(),
                    [](char c) {
                        return !isspace<char>(c, locale::classic());
                    });
    s.erase(s.begin(), it);
    return s;
}
 
string& rtrim(string &s)
{
    auto it = find_if(s.rbegin(), s.rend(),
                    [](char c) {
                        return !isspace<char>(c, locale::classic());
                    });
    s.erase(it.base(), s.end());
    return s;
}
 
string& trim(string &s) {
    return ltrim(rtrim(s));
}*/

//Method 3
/*string trim(string &text){
    auto start = text.begin();
    while(start != text.end() && isspace(*start)){
        start++;
    }
    
    auto end = text.end();
    do{
        end--;
    }
    while(distance(start, end) > 0 && isspace(*end));
    
    return string(start, end + 1);
}*/

int main()
{
    char data_1[16] = " James ";
    char data_2[16] = "\x20\x20\x31\x32\x33\x20";
    string data_3 = " Nadia   ";

    //Mehotd 1
    cout << "[" << trim(data_1) << "]" << endl;
    cout << "[" << trim(data_2) << "]" << endl;
    cout << "[" << trim((char *) data_3.c_str()) << "]" << endl;

    //Method 2 & 3
    //cout << "[" << trim(data_3) << "]" << endl;
    
    system("pause");

    return 0;
}