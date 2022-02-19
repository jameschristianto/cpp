#include <iostream>
#include <list>

using namespace std;

class HashTable
{
private:
    int bucketSize;
    list<int> *table;

public:
    HashTable(int size)
    {
        bucketSize = size;
        table = new list<int>[bucketSize];
    }

    int hashFunction(int key)
    {
        return key % bucketSize;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        list<int>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); it++)
        {
            if (*it == key)
            {
                table[index].erase(it);
                break;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            cout << "Bucket " << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    HashTable ht(5);

    ht.insert(1);
    ht.insert(17);
    ht.insert(9);
    ht.insert(24);
    ht.insert(32);

    ht.print();

    ht.remove(17);

    ht.print();

    system("pause");

    return 0;
}