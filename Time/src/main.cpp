#include <iostream>
#include <ctime>

using namespace std;

const char *nameDay[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; //Declare name of day

int main()
{
    time_t timeNow = time(NULL); //Get time from OS
    char *getTime = ctime(&timeNow);
    tm getTimeStruct = *localtime(&timeNow); //Change localtime to gmtime for UTC time

    //String type
    cout << "Time Now : " << getTime << endl;

    //Integer Type
    cout << "Day    : " << nameDay[getTimeStruct.tm_wday] << endl;
    cout << "Date   : " << getTimeStruct.tm_mday << endl;
    cout << "Month  : " << getTimeStruct.tm_mon + 1 << endl; //Start from January then plus 1
    cout << "Year   : " << getTimeStruct.tm_year + 1900 << endl << endl; //Start from 1900 then plus 1900

    cout << "Second : " << getTimeStruct.tm_sec << endl;
    cout << "Minute : " << getTimeStruct.tm_min << endl;
    cout << "Hour   : " << getTimeStruct.tm_hour << endl;

    cin.get();

    return 0;
}
