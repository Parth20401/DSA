class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        //create max heap for first k elements
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        //for rest elements, check if current element < heap.top
        for(int i=k; i<=r; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        //the final heap created will have k'th smallest element as its root
        return pq.top();
    }
};
//TC - O(nlog(k))
//SC - O(K)
