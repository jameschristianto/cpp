#include <iostream>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

void Func();

class Timer{
public:
    time_point<steady_clock> timeStart, timeEnd; //There is three option (starting point and tick rate) system_clock, steady_clock and high_resolution_clock
    duration<float> interval; //you can change float to double

    //Constructor for start counting time
    Timer(){
        timeStart = steady_clock::now(); //Make sure the option same with time_point
    }

    //Destructor for end counting time
    ~Timer(){
        timeEnd = steady_clock::now(); //Make sure the option same with time_point
        interval = timeEnd - timeStart;

        cout << interval.count() << " s" << endl;
    }

    float getTime(){
        timeEnd = steady_clock::now();
        interval = timeEnd - timeStart;

        return interval.count();
    }
};

int main()
{
    Func();

    cin.get();

    //system("pause"); //Pause

    return 0;
}

void Func(){
    Timer obTimer; //Create object

    for(int i = 1; i <= 10; i++){
        cout << i << endl;
        Sleep(500); //Sleep for 0.5 second
    }
}
