#include <iostream>
#include <string>
#include <vector>

using namespace std;
////////////
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
///////////  
void bubbleSort(vector <int> &arr)
{
 int i, j;
 bool swapped;
 for (i = 0; i < arr.size(); i++)
 {
   swapped = false;
   for (j = 0; j < arr.size()-1; j++)
   {
    if (arr[j] > arr[j+1])
    {
      swap(&arr[j], &arr[j+1]);
      swapped = true;
    }
   }
    if (swapped == false)
	break;
  }
}

//////////////////
int partition (vector <int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
               if (arr[j] < pivot)
        {
            i++; 
 	    swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 ////////////////
void quickSort(vector <int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/////////// 
void selectionSort(vector <int> &arr) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < arr.size()-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < arr.size(); j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  

//////////////////////
void printArray(vector <int> &arr)
{
    int i;
    for (i = 0; i < arr.size(); i++)
    {    
        cout <<" "<< arr[i];
    }
    	cout <<" "<< endl;
}
  
int main()
{
   vector <int> arr = {7, 3, 5, 2, 4, 1, 9, 6, 8};
  // bubbleSort(arr);
   quickSort(arr, 0, arr.size()- 1);
  // selectionSort(arr);
    printArray(arr);
    return 0;
}
