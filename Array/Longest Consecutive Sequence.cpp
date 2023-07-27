class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        sort(nums.begin(), nums.end());
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == lastSmaller) continue;
            else if((nums[i] - 1) == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            //if not equal, start the count again
            else if((nums[i] - 1) != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            //we want max of all combinations of count
            longest = max(longest, cnt); 
        }
        return longest;
    }
};

//TC - O(N*log(N))
//SC - O(1)
