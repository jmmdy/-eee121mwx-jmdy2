#include <iostream>
using namespace std;
#include <math.h> //for pow function

int greedy(int *arr,int n, int level, int H, int v) {
    int child1, child2, favchild;
    child1 = n*2 + 2; 
    child2 = (n*2) + 1;
    // cout << n << endl << child1 << endl << child2 << endl;
    if (arr[child1] > arr[child2])
        favchild = child1;
    else
        favchild = child2;
    v += (arr[favchild]);
    if (level == H -1 ) {
        cout << v;
        return 0;
    } else {
        level++;
        return greedy(arr, favchild, level, H, v);
    }
}

int dynamic(int *arr, int H) {
    int num = pow(2, H) - 1; // number of total nodes
    int num2 = pow(2, H-1); // number of nodes of the bottom level
    
    int arr2[num];
    for (int i=1; i < num2 + 1; i++) {
        arr2[num-i] = arr[num-i];
    }
    for (int i = H-1; i > 0; i--) {
        int num3 = pow(2, i) - 1; //total number of nodes, starting with the last level with children

        for (int j = num3; j< (num3*i) + 1; j+=2) { 
            int node = ((j+1)/2) - 1; 
            if(arr2[j]>arr2[j+1]){
                arr2[node] = arr[node] + arr2[j];
            } else {
                arr2[node] = arr[node] + arr2[j+1];
            }
        
        }
    }
    cout << arr2[0];

    return 0;
}

int main() {
    int T, H, num;
    cin >> T;
    
    for(int i=0; i < T; i++) {
        cin >> H;
        num = pow(2, H) - 1;
        int arr[num];
        
        for(int j=0; j < num; j++) {
            cin >> arr[j];
        }
        cout << "Greedy: ";
        greedy(arr, 0, 1, H, arr[0]);
        cout << " Dynamic: ";
        dynamic(arr, H);
        cout << endl;
    }
    return 0;
}