#include <iostream>
using namespace std;

int arr1[5][5] {}  //create 5x5 array
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        cin >> arr1[i][j]; 
}};

int arr2[5][5] {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr2[i][j]; 
    }
    }};

int arradd[5][5]; 
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        arradd[i][j] = arr1[i][j] + arr2[i][j];
        cout << arradd[i][j] << " "; 
}};

int arrmul[5][5]; 
for(int j = 0; j < 5; j++) {
    for(int i = 0; i < 5; i++) {
        arrmul[i][j] = 0;
        arrnmul[i][j] = arr1[i][j] * arr2[i][j];
        cout << arrmul[i][j] << " "; 
}};

