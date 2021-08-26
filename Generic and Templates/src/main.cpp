#include <iostream>

using namespace std;

//create method 1
template <typename T>
void printFunc(T text)
{
    cout << "Your text : " << text << endl;
}

//create method 2
template <class T>
class printClass
{
    T var;

public:
    printClass(T var){
        this->var = var;
    }

    void print(){
        cout << "Your text : " << var << endl;
    }
};

int main()
{
    //call function method 1
    printFunc(1);
    printFunc('A');
    printFunc("James");

    cout << endl;

    //call funtion method 2
    printFunc<int>(1);
    printFunc<char>('A');
    printFunc<string>("James");

    cout << endl;

    //call class
    printClass<int> myClass1(1);
    myClass1.print();
    printClass<char> myClass2('A');
    myClass2.print();
    printClass<string> myClass3("James");
    myClass3.print();

    system("pause");
    return 0;
}