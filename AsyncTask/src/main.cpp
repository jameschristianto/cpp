#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>

using namespace std;

// Without promise
/*long int sumNumber(long int start, long int end){
    long int result;

    for(long int i = start; i <= end; i++){
        result += i;
    }

    return result;
}

int main()
{
    long int start = 0, end = 100000;

    future<long int> total = async(launch::deferred, sumNumber, start, end); // deferred means not create new thread (blocking or same thread)

    cout << "Waiting..." << endl;
    cout << total.get() << endl; // await

    system("pause");
    return 0;
}*/

// With promise
void sumNumber(promise<long int> &&totalPromise, long int start, long int end)
{
    long int result;

    for (long int i = start; i <= end; i++)
    {
        result += i;
    }

    totalPromise.set_value(result); // set value promise
}

int main()
{
    long int start = 0, end = 100000;

    promise<long int> totalPromise;                                // create promise
    future<long int> totalFuture = totalPromise.get_future();      // create future from promise
    thread totalThread(sumNumber, move(totalPromise), start, end); // create thread

    cout << "Waiting..." << endl;
    cout << totalFuture.get() << endl; // await value promise
    totalThread.join();

    system("pause");
    return 0;
}