#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mx;

void addAmount(int &amount)
{
    mx.lock();

    amount++;

    mx.unlock();
}

int main()
{
    int amount = 0;

    thread th1(addAmount, ref(amount));
    
    thread th2(addAmount, ref(amount));

    th1.join();
    th2.join();

    cout << amount << endl;

    system("pause");
    return 0;
}