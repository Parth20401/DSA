class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();

        for(int i=0; i<n; i++){
            count[nums[i]]++;
        }
         for(auto& c:count){
             if(c.second > n/2){
                return c.first;
                break;
            }
        }
        return 0;
    }
};
