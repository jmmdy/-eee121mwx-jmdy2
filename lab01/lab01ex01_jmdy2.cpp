
#include <iostream>
using namespace std;

int gcd(int input1, int input2) {
    int rem = 0;
    int greaternum = input1;
    int smallernum = input2;
    if (input2 > input1) { //incase input2 is greater than input1

        greaternum = input2;
        smallernum = input1;
    };
    
    while (smallernum != 0) {
        rem = greaternum % smallernum; //gets the remainder of the two numbers
        greaternum = smallernum; //changes input1 with input2 for the next loop
        smallernum = rem; 
    }
    
    return int(greaternum);
}
int lcm(int input1, int input2) {
    int lcm;
    int gcd1 = gcd(input1, input2);
    lcm = (input1 * input2)/gcd1; //equation for the lcm
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