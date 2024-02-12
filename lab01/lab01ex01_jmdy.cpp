
#include <iostream>
using namespace std;

int gcd(int input1, int input2) {
    int rem;
    if (input2 > input1) { //incase input2 is greater than input1
        int newnum;
        newnum = input1;
        input1 = input2;
        input2 = newnum;
    };
    rem = input1 % input2; //gets the remainder of the two numbers
    input1 = input2; //changes input1 with input2 for the next loop
    input2 = rem; 

    
    return int(input2);
}
int lcm(int input1, int input2) {
    int lcm;
    lcm = input1*input2/gcd(input1, input2); //equation for the lcm
    return lcm;
}

int main() {
    int input1;
    int input2;
    cin >> input1;
    cin >> input2;
    cout << gcd(input1, input2) <<endl;
    cout << lcm(input1, input2);

    return 0;
}