#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print(q);

    q.pop();

    print(q);

    cout << "Size : " << q.size() << endl;

    system("pause");

    return 0;
}