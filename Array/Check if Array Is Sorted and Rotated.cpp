class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        for(int i=1; i<nums.size(); i++){
            //check if array is sorted and rotated
            if(nums[i - 1] > nums[i])
                c++;
        }
            //check if arrays is sorted only(or rotated by x=0 positions)
            if(nums[nums.size() - 1] > nums[0])
                c++;

            return c <= 1;
    }
};
