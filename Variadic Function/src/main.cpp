#include <iostream>
#include <cstdarg>

using namespace std;

void variadic(int size, ...){
    va_list value; //init argument list
    va_start(value, size); //set first value argument
    int count = 0;

    while(count < size){
        cout << va_arg(value, int) << endl; //get next argument
        count++;
    }

    va_end(value); //clean up
}

int main()
{
    variadic(5, 1, 2, 3, 4, 5);
    cin.get();
    return 0;
}
