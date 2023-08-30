class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = nums.size() - 1;

        //insert first k elements into min heap
        for(int i=0; i<k; i++){
            minHeap.push(nums[i]);
        }

        //process remaining elements
        for(int i=k; i<=n; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        //now, top of heap will have k'th largest element
        return minHeap.top();
    }
};
