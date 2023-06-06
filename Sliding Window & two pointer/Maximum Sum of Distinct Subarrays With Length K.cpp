class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long ans = 0, sum = 0;
        int i = 0;
        while(i < k && i < nums.size()){
            mp[nums[i]]++; //storing first k elements in map
            sum += nums[i];
            i++;
        }
        //checking for duplicate elements
        if(mp.size() == k)
            ans = sum; //storing sum of first window of k elements

        //now process next windows
        while(i < nums.size()){
            mp[nums[i]]++;
            mp[nums[i - k]]--; //removing the 1st key from previous iteration

            if(mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);

            sum += nums[i];
            sum -= nums[i - k];

            if(mp.size() == k)
                ans = max(ans, sum);
            
            i++;
        }
        return ans;    
    }
};
