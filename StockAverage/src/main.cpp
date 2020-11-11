#include <iostream>

using namespace std;

int currentStock, currentLot, yourStock, yourLot;
float avgStock, profit;

int main()
{
    while(1){
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

        profit = (float)((currentStock * (currentLot + yourLot) * 100) - (yourStock * (currentLot + yourLot) * 100));
        cout << "Profit            : " << profit << endl << endl;
    }

    system("pause");

    return 0;
}
