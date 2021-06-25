#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sentence = "i love c++";

int main()
{
    //raw string
    cout << "raw string : " << sentence << endl;

    cout << endl;

    //looping string for
    for(unsigned int i = 0; i < sentence.length(); i++){
        cout << "[" << sentence[i] << "]" << endl;
    }

    cout << endl;

    //parsing using sub string
    cout << sentence.substr(0, 1) << endl;
    cout << sentence.substr(sentence.find("love"), 4) << endl;
    cout << sentence.substr(sentence.find("c++")) << endl;

    cout << endl;

    //delimiter
    string delimiter = " ";
    unsigned int start = 0;
    unsigned int end = sentence.find(delimiter);
    vector<string> result;

    while(end != string::npos){
        result.push_back(sentence.substr(start, end - start));
        start = end + delimiter.length();
        end = sentence.find(delimiter, start);

        if(end == string::npos){
            result.push_back(sentence.substr(start, end - start));
        }
    }

    for(string x : result){
        cout << x << endl;
    }

    cout << endl;

    //find word and word between quotes
    string x = "names = \"james\"";
    start = x.find("\"");
    end = start + 1;

    if(x.find("name") != string::npos /*&& x.substr(x.find("name") + 4, 1) == " "*/){
        cout << "found" << endl;
        cout << x.substr(end, x.find("\"", end) - end) << endl;
    }
    else cout << "not found" << endl;

    cin.get();

    return 0;
}
