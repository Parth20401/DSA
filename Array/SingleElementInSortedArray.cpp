class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        if(nums[s]!=nums[s+1])
            return nums[s];
        if(nums[e]!=nums[e-1])
            return nums[e];

        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            else if((nums[mid]==nums[mid+1] && mid%2==0) || (nums[mid]==nums[mid-1] && mid%2!=0))
                s=mid+1;
            else
                e=mid-1; 
        }
        return -1;
        }
};
