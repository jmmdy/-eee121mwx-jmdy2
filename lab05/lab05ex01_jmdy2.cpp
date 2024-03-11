
#include <iostream> 
#include <bitset> 
using namespace std; 

void recurse(string a, int n, int m) 
{ 
	if (n == m) 							//when the "n" counter reaches the length of the string. Basically counts how many branches in a tree until the output will be printed.
		cout << a << endl; 
	else { 
		for (int i = n; i < m; i++) { 		//n determines the item in the array that will be "focused", m is the string length
			if ((a[i] == a[n] && i != n) && (i>n && a[i] == a[i-1])) { //to check for duplicates
				continue;
			} else {
				swap(a[n], a[i]); 			//swaps 
				recurse(a, n + 1, m); 		//recursion by increasing n,  
				swap(a[n], a[i]); 			//swaps the two items back for the backtracking
			}
		} 
	} 
} 

int main() 
{ 
	string input1;
	cin >> input1;
	recurse(input1, 0, input1.length()); //starting at 0
	return 0; 
} 

//Time Complexity: O(n!) - because each line that is being produced takes n amount of time, so the time it takes to print all the lines is the number of lines multiplied to each other, which is n!.
//Space Complexity: O(n(n!)) - each line takes n space, hence n! for the total number of lines. Additionally, each branch going down is also counted, therefore an additional n is multiplied.
