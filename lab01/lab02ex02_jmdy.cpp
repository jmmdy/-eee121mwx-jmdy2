#include <iostream>
using namespace std;

int main() {
    int arr1[5][5]; //create 5x5 array
        for(int i = 0; i < 5; i++) { //rows
            for(int j = 0; j < 5; j++) { //columns
                cin >> arr1[i][j]; //input per cell
        }};
    
    int arr2[5][5];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> arr2[i][j]; 
        }
        };
    
    int arradd[5][5]; 
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                arradd[i][j] = arr1[i][j] + arr2[i][j]; //formula
        }};
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << arradd[i][j] << " "; //printing with space in between each cell
                if (j == 4) 
                    cout << endl; //new line when there is 5 cells per line
        }};
    
    int arrmul[5][5]; 
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                arrmul[i][j] = 0;
                for(int k = 0; k < 5; k++){ //extra variable for dot product
                    arrmul[i][j] += arr1[i][k] * arr2[k][j]; //formula
        }}};
        for(int j = 0; j < 5; j++) {
            for(int i = 0; i < 5; i++) {
                cout << arrmul[i][j] << " ";
                if (i == 4)
                    cout << endl;
        }};
        
return 0; 
    
}