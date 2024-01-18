class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefixsum
        unordered_map<int, int> mp;
        mp[0] = 1;//initially
        int preSum = 0, cnt = 0;

        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];//finding prefix sum
            int remove = preSum - k;//now subtract elements coming before so that new subarray sum can be found
            cnt += mp[remove];//count of removed element (can be >1) will be added to the ans
            mp[preSum] += 1;
        }
        return cnt;
    }
};
//TC - O(n * log n)-> log n depending upon map (can be between 1 and n)
//SC - O(N)
