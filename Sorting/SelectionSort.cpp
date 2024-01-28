#include <bits/stdc++.h>

using namespace std;
void selectionSort(int arr[],int n)
{
    int min;
    for(int i=0;i<n;i++){
        min=i;
        //now finding the minimum in the array to be swapped
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j])
            min=j;
        }
            swap(arr[min],arr[i]);
        
        }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
    
int main()
{
    int arr[]={45,76,12,32,19,5,76,677,4,69,54};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);

    return 0;
}
//TC - O(n^2)
