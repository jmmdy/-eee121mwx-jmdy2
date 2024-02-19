#include <iostream>
using namespace std;

int* pointerfunc(int size) {
    int* outval = new int[size]; //takes in the size from main(), creates an array, and allocates space
    return outval;
};

int main() {
    int size = 5; //set size 
    int *array = pointerfunc(size); //array has allocated space
    for(int i = 0; i < 5; i++)
        cin >> array[i]; //inputs
    for(int i = 0; i < 5; i++)
        cout << array[i]; //prints
    delete [] array; //delete the used space afterwards
    return 0;
}