class Solution{
    public:
    void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){ 
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){ 
        largest = right;
    }
    //if largest has been updated
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); //call for further nodes to be in correct position
    }
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //merge both the vectors
        vector<int> ans;
        for(auto i: a)
            ans.push_back(i);
        for(auto i: b)
            ans.push_back(i);
            
        //build heap using merged vector
        int size = ans.size();
        //0-based indexing
        for(int i=size/2 - 1; i>=0; i--){
        heapify(ans, size, i);
        }
    return ans;
    }
};
