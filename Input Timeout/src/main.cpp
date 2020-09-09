/**************************************************
This source using Future and Thread Library
If an error occurred
Please install high version of GCC
**************************************************/

#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <cstdlib>
#include <time.h>

using namespace std;

int getInteger();

int main()
{
    int inFirst, inSecond, inAnswer;

    srand (time(NULL));
    inFirst = (rand() % 100) + 1;
    inSecond = (rand() % 100) + 1;
    inAnswer = inFirst + inSecond;

    cout << inFirst << " + " << inSecond << " = ";

    auto timeStart = chrono::high_resolution_clock::now();

    future<int> futureInteger = async(launch::async, getInteger);

    chrono::system_clock::time_point time_passed = chrono::system_clock::now() + chrono::seconds(10); //Set timeout value
    future_status status = futureInteger.wait_until(time_passed);

    if(status == future_status::ready){
        int inValue = futureInteger.get();

        if(inValue == inAnswer) cout << "Correct!!!" << endl;
        else cout << "Wrong!!! The Answer is " << inAnswer << endl;
    }
    else{
        cout << endl << "Timeout..." << endl;
    }

    auto timeEnd = chrono::high_resolution_clock::now();

    this_thread::sleep_for(1s);

    chrono::duration<double> timePassed = timeEnd - timeStart;
    cout << "Time passed : " << timePassed.count() << " s" << endl;

    cin.get();

    return 0;
}

int getInteger(){
    string srInput;
    int inInput;

    getline(cin, srInput);
    inInput = stoi(srInput);

    return inInput;
}
