#include <iostream>

using namespace std;

int currentStock, currentLot, yourStock, yourLot;
float avgStock;

int main()
{
    cout << "Input current stock price : ";
    cin >> currentStock;
    cout << "Input current stock lot   : ";
    cin >> currentLot;

    cout << "Input your average stock price : ";
    cin >> yourStock;
    cout << "Input your stock lot           : ";
    cin >> yourLot;

    avgStock = (float)((currentStock * currentLot) + (yourStock * yourLot)) / (currentLot + yourLot);
    cout << "New average stock : " << avgStock << endl;

    system("pause");

    return 0;
}
