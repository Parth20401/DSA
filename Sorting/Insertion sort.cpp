class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        //move from the last element and keep the sorted element in there
        for(int i=n-1; i>=0; i--){
            //now j loop will go through entire array and compare the adjacent element
            //until i-1 goes(bcos after that all elements are already sorted)
            for(int j=0; j<i; j++){
                if(arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
};
//TC - O(n^2)-worst and average
//O(n)- best case
