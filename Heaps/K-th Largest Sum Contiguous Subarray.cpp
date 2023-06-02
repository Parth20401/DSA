class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int> > minHeap;

        for(int i=0; i<N; i++){
            int sum = 0;
            
            for(int j=i; j<N; j++){
                sum += Arr[j];
                //if size of heap is less than K
                if(minHeap.size() < K){
                  minHeap.push(sum);  
                }
                else{
                    if(sum > minHeap.top()){
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
            }
        }
        return minHeap.top();
    }
};
//SC - O(K)
