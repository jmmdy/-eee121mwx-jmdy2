#include <iostream>
using namespace std;

int partition(int sortarr[],int start,int end) //handles all the sorting
{
  int pivot=sortarr[end]; //the rightmost value will be the pivot
  int begi=(start-1);    
  for(int i=start;i<=end;i++)
  {
    if(sortarr[i]<pivot) 
    {
      begi++; //move on to next item
      swap(sortarr[begi],sortarr[i]); //if the item being checked is less than the pivot, swap the first item in the sortarray with the item being checked
    }
  } //for loop will do nothing if the item being checked is greater than or equal to the pivot
  swap(sortarr[begi+1],sortarr[end]); //putting the pivot item in its right position in the sortarray
  return (begi+1); //return value in order to move on to the next items in the sortarray
}

            
void quicksort(int sortarr[],int start,int end)
{

  if(start<end)
  {
     
    int part=partition(sortarr,start,end); //getting the return value of the partition, or the one that is equal to or greater than the partition
     
    quicksort(sortarr,start,part-1);
    quicksort(sortarr,part+1,end);
    //these two recursions makes sure that every item is taken into account beside the return value of partition
  }
}


int main() {
  int input1;

  cin >> input1;
  int sortarr[input1];
  for (int i = 0; i < input1; i++){
      cin >> sortarr[i];
  }

  quicksort(sortarr,0,input1-1); //initial call
  cout<<"Quicksorted array"<<endl;
  for(int i=0;i<input1;i++)
  {
    cout<<sortarr[i]<<endl;
  }
  return 0;
}


//Average Time Complexity: O(nlog(n)) - dividing the into the partitions over and over again
//Worst Case Time Complexity: O(n^2) - will have to go back and forth between each item in the array
//Average Space Complexity: O(log(n)) - the additional space needed decreases after a certain amount of space is reached
//Worst Case Space Complexity: O(n) - takes the same amount of space as the inputs - there are the same number of output lines as input lines

