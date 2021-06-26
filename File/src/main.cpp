#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string filePath = "assets/file.txt";

int main()
{
    //use fstream that is able to read and write file

    //write file
    ofstream outFile(filePath);
    //ofstream outFile(filePath, ios::app); //with append
    if(outFile.is_open()){
        cout << "able to open file";

        outFile << "This is a line.\n";
        outFile << "This is another line.\n";
        outFile.close();
    }
    else cout << "Unable to open file" << endl;

    //read file
    string line;
    ifstream inFile(filePath);
    if(inFile.is_open()){
        cout << "able to open file" << endl;
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    }
    else cout << "Unable to open file" << endl;

    cin.get();

    return 0;
}
