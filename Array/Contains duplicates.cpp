class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        for(auto& c:count){
            if(c.second >= 2){
                return true;
            }
        }
        return false;
    }
};

//set approach
// Set Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
    }
}; //appraoch is based on that set cannot contain duplicate elements
