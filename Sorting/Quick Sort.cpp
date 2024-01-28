class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int pIndex = partition(arr, low, high);
            
            //call quicksort for left side of pivot
            quickSort(arr, low, pIndex - 1);
            
            //call quicksort for right side of pivot
            quickSort(arr, pIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot = arr[low];
       int i = low;
       int j = high;
       
       while(i < j){
           
        while(arr[i] <= pivot && i < high)
            i++;
                
        while(arr[j] > pivot && j > low)
            j--;
            
        if(i < j)
            swap(arr[i], arr[j]);
       }
       swap(arr[low], arr[j]);
       return j;
    }
};

//TC - O(nlogn) - best and avg case
//O(n^2) - worst case
