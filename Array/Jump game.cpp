class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;

        for(int i=0; i<nums.size(); i++){
            //check if i > reachable(if true means we cannot reach last index)
            if(i > reachable)
                return false;

            reachable = max(reachable, i + nums[i]);//we take the max number of jumps that should be taken
        }
        return true;
    }
};
