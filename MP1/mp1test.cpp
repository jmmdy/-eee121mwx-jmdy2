#include <iostream>
#include <string>
using namespace std;


int main() 
{ 
    int arr[5][5];
    for (int i=0; i<5; i++) {
        cout << ((rand() % (20 - 1 + 1)) + 1) << " ";
        arr[0][i] = ((rand() % (20 - 1 + 1)) + 1);
    }
    for (int i = 0; i < 5 ; i++) {
        for (int j=0; j<5; j++) {
            cout << arr[i][j] << endl;
        }}
} 

//((rand() % (20 - 1 + 1)) + 1)
