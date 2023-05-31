#include <bits/stdc++.h> 
void heapify(vector <int>& arr, int n, int i){
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }
    //if smallest has been updated
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest); //call for further nodes to be in correct position
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    //only process for non leaf nodes, as they are in correct position
    for(int i=n/2; i>=0; i--){  //0-based indexing
        heapify(arr, n, i);
    }
    return arr;
}
