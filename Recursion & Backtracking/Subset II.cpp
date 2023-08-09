class Solution {
public:
    void solve(int index, vector<int> nums, int n, vector<int> temp, vector<vector<int>>& ans){
        ans.push_back(temp);
    
        //skipping duplicates
        for(int i=index; i<n; i++){
            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }
    
        temp.push_back(nums[i]);
        solve(i + 1, nums, n, temp, ans);
        temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, n, temp, ans);
        return ans;
    }
};

//TC - O(2^n)
//SC - O(2^n * k)
