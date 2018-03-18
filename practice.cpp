// Vidhur Vashisht
// Data Structures
// March 5th 2018

#include <iostream>
#include <iomanip>
#include <climits>

int size1 = 7;
int size2 = 5;
int size3 = 4;

using namespace std;

int StairCase(int n);
int countWays(int n);
int FirstIndex(int arr[], int first, int last, int found, int size1);
int rotate(int arr[], int d, int n);
int RecoverArray(int arr[]);
int swap(int i, int j, int arr[]);
int partition(int arr[], int first, int last);
int pivot(int arr[], int first, int last, int k);
int partition_alter(int arr[], int b, int c);
int kthSmallest(int arr[], int first, int last, int k);
int findMedian(int arr[], int value);

int main()
{
   int climb, n1, n2, first, last, found = 3, k = 4, l = 3;
   int arr1[] = {1,2,3,3,4,5,10};
   int arr2[] = {4,5,1,2,3};
   int arr3[] = {1,3,4,2,7,5,9};
   int arr4[] = {7,9,4,5};
   int arr5[] = {4, 3, 2, 1};
   
   int num1 = sizeof(arr2) / sizeof(arr2[0]);
   int num2 = sizeof(arr4) / sizeof(arr4[0]);
   int num3 = sizeof(arr5)/sizeof(arr5[0]);
   
   // Question 1
   cout << endl << "Question 1" << endl;
   cout << "Enter a number for n :";
   cin >> n1;
   n1 = StairCase(n1);
   
   cout << "There are " << n1 << " ways of climbing the stairs" << endl;
   
   // Question 2
   cout << endl << "Question 2" << endl;
   cout << "arr[] = ";
   for(int j = 0; j < size1; ++j)
      cout << setw(3) << arr1[j];
   cout << endl;
   cout << "The first index of " << found << " is : "; 
   cout << FirstIndex(arr1, 0, size1 - 1, found, size1) << endl;

   // Question 3 
   
   cout << endl << "Question 3" << endl;
   cout << "Rotated array [] = ";
   for(int n = 0; n < size2; n++)
      cout << setw(3) << arr2[n];
   cout << endl;
   RecoverArray(arr2);
   cout << "Original array [] = ";
   for(int n = 0; n < size2; n++)
      cout << setw(3) << arr2[n];
   cout << endl;    
   
      // Question 4
   cout << endl;
   cout << "Question 4" << endl;
   cout << "K'th smallest element is: " << pivot(arr5, 0, num3, l); 
   cout << endl;
 
   // Question 5 
   cout << endl;
   cout << "Question 5" << endl;
   cout << "Given array {4, 5, 1, 2, 3} " << endl;
   cout << "The median of the array is: " << findMedian(arr2, num1);
   cout << endl;
   cout << "Given array {7, 9, 4, 5} " << endl;
   cout << "The median of the array is: " << findMedian(arr4, num2);
   cout << endl;
   
   return 0;
}

// Question 1
          
int StairCase(int n)
{         
   if(n <= 3)
      return n;     
   else
      return StairCase(n - 1) + StairCase(n - 2);
   cout << endl;
}   

// Question 2

int FirstIndex(int arr[], int first, int last, int found, int size1)
{
   if (first <= last)
   {
      int mid = first + (last - first)/2;
      if(arr[mid] == found && arr[mid - 1] < found || mid == 0 )
         return mid;
      else if(arr[mid] < found)
         return FirstIndex(arr, mid + 1, last, found, size1);
      else 
         return FirstIndex(arr, first, mid - 1, found, size1);
   }
      else
         return -1;
   
   cout << endl;
}

// Question 3 

int rotate(int arr[], int d, int n)
{
   int temp[d];
   int it = 0;
   
   for(int i = 0; i < d; ++i)
      temp[i] = arr[i];   	   
   for(int k = 1; k < n; ++k)
      arr[k] = arr[k + d];
   for(int p = n - d; p < n; ++p)
      arr[p] = temp[it++]; 	
}

int RecoverArray(int arr[])
{
   int temp;
   bool swapped = false;

   do
   {
      swapped = false; 
      for (int j = 1; j < size2; j++) 
      {
         if (arr[j-1] > arr[j])  
         { 
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            swapped = true;
         }
      }
   } while (swapped);
}

// Question 4

int swap(int i, int j, int arr[])
{
   int temp;
   
   temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int partition(int arr[], int first, int last)
{
   int i = first, pivot = arr[last];
   for (int j = first; j <= last - 1; j++)
      if (arr[j] <= pivot)
      {
         swap(arr[i], arr[j]);
         i++;
      }
   swap(arr[i], arr[last]);
   return i++;  
}

int pivot(int arr[], int first, int last, int k)
{
   int pivotIndex = partition(arr, first, last);
   if (k < pivotIndex - first + 1)
   {
      return pivot(arr, first, pivotIndex - 1, k);
   }
   else if (k == pivotIndex - first + 1)
      return arr[pivotIndex];
   else
      return pivot(arr, pivotIndex + 1, last, k - (pivotIndex - first + 1));
}

// Question 5

int partition_alter(int arr[], int b, int c)
{
    int var = arr[c], i = b;
    for (int j = b; j <= c - 1; j++) 
    {
        if (arr[j] <= var) 
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[c]);
    return i;
}

 
int kthSmallest(int arr[], int first, int last, int k)
{
    if (k > 0 && k <= last - first + 1) 
    {
        int index = partition_alter(arr, first, last);
        if (index - first == k - 1)
            return arr[index];
        if (index - first > k - 1) 
            return kthSmallest(arr, first, index - 1, k);
 
        return kthSmallest(arr, index + 1, last, k - index + first - 1);
    }
    return INT_MAX;
}

int findMedian(int arr[], int value)
{
    int median;
    if(value%2 == 1)
    {
        median = value/2 + 1;
    }
    else
    {
        median = value/2;
    }
    return kthSmallest(arr, 0, value - 1, median);
}
