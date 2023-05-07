class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];  //update complement at every iteration
            if(mp.find(complement) != mp.end()){
                ans.push_back(mp[complement]); //insert the number into ans
                ans.push_back(i);// insert it's index into ans
            }
            else{
                    mp.insert({nums[i], i});  //if not found, insert that number and it's index
            }
        }
        return ans;
    }
};
