/**************************************************
memmove can be replace with memcpy according to
the needs.

memmove can handle overlapping memory whereas,
memcpy can't

memcpy is faster than memmove, use memmove when
it is overlapping memory
**************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int inArray[6] = {1, 2, 3, 4, 5};
char szArray[] = "James";

int inSize, inSize2, i;

int inFrom, inTo; //Element of Array

int main()
{
    inSize = sizeof(inArray) / sizeof(inArray[0]); //Length of array inArray
    inSize2 = sizeof(szArray) / sizeof(szArray[0]); //Length of Array szArray

    //Move/copy all of element, shift right or shift left
    for(i = 0; i < inSize; i++){
        cout << "Array Element" << i + 1 << " : " << inArray[i] << endl;
    }

    inFrom = 2;
    inTo = 1;
    memmove(&inArray[inTo], &inArray[inFrom], (inSize - inTo - 1) * sizeof(*inArray)); //inSize - 1 means length array minus 1 cause array element start from zero, then minus inTo cause will move to element inTo
    //memcpy(inArray+inTo, inArray+inFrom, (inSize - inTo - 1) * sizeof(*inArray)); //Another method
    cout << endl;

    for(i = 0; i < inSize; i++){
        cout << "Integer Array " << i + 1 << " : " << inArray[i] << endl;
    }

    //Move/copy just one element
    inFrom = 1;
    inTo = 0;
    memmove(&inArray[inTo], &inArray[inFrom], sizeof(*inArray));
    //memcpy(inArray+inTo, inArray+inFrom, sizeof(*inArray)); //Another method
    cout << endl;

    for(i = 0; i < inSize; i++){
        cout << "Integer Array " << i + 1 << " : " << inArray[i] << endl;
    }

    //Move/copy for char array
    cout << endl;
    cout << "Char Array : " << szArray << endl;

    inFrom = 2;
    inTo = 0;
    memmove(&szArray[inTo], &szArray[inFrom], (inSize2 - inTo - 1) * sizeof(*szArray));
    //memcpy(&szArray[inTo], &szArray[inFrom], (inSize2 - inTo - 1) * sizeof(*szArray)); //Another method

   cout << "Char Array : " << szArray << endl;

    system("pause");

    return 0;
}
