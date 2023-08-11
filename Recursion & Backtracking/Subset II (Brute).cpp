class Solution {
public:
    void solve(set<vector<int>>& res, vector<int> ds, int index, vector<int>& nums){
        //base case
        if(index == nums.size()){
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }

        //pick the element
        int element = nums[index];
        ds.push_back(element);
        solve(res, ds, index + 1, nums);
        ds.pop_back();

        //not pick
        solve(res, ds, index + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        solve(res, ds, 0, nums);

        //to convert set into vector
        for(auto it=res.begin(); it!=res.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};

//TC - O(2^n * klog(x)) - 2^n means to generate every subset
//Sc- O(2^n * k)
