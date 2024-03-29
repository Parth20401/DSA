#include <bits/stdc++.h> 
int merge(long long *arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count += (mid - left + 1); //count possible pairs
            right++;
        }
    }

    while(left <= mid){// if the left pointer exceed means add the remaining left  values
        temp.push_back(arr[left]);
        left++;
    }

     while(right <= high){// if the right pointer exceed means add the remaining left  values
        temp.push_back(arr[right]);
        right++;
    }
    //transferring values from temp to arr
    for(int i=low; i<=high; i++){
        arr[i] = temp[i - low];
    }
    return count;
}

int mergeSort(long long *arr, int low, int high){
    int count = 0;

    if(low == high)  return count;

    int mid = (low + high)/2;

    count += mergeSort(arr, low, mid);//to get the 1 sorted array
    count += mergeSort(arr, mid + 1, high);//to get the 2 sorted array
    count += merge(arr, low, mid, high);//finally merger the two sorted array

    return count;
}

long long getInversions(long long *arr, int n){
  return mergeSort(arr, 0, n - 1);
}
