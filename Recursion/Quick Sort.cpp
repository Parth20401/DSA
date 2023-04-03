//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    int partition (int arr[], int s, int e)
    {
       int pivot=arr[s];
       
       int count=0;
       //to put pivot in the right place
       for(int i=s+1; i<=e;i++){
           if(pivot>=arr[i])
                count++;
       }
       int pivotIndex = s+count;
       swap(arr[pivotIndex],arr[s]);
       
       int i=s, j=e;
       //to take care of left and right part of pivotIndex
       while(i < pivotIndex && j > pivotIndex){
           while(arr[i] <= pivot)
                i++;
            
            while(arr[j] > pivot)
                j--;
       if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++] , arr[j--]);
            
       }
            
        return pivotIndex;
    }
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        //base case
        if(low>=high)
            return;
            
        int p=partition(arr,low,high);
        
        quickSort(arr,low,p-1); //sort elements before p
        quickSort(arr,p+1,high); //sort elements after p
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
