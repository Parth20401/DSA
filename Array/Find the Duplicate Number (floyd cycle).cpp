class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(fast != slow){
            //using floyd's cycle
            slow = nums[slow]; 
            fast = nums[nums[fast]];
        }

        fast = nums[0];
        //now both ptrs move at 1 step per iteration
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};
