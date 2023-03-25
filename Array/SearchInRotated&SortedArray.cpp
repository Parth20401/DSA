class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        while(hi>=lo)
        {
          int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[lo]<=nums[mid]){   //check if left half is sorted
                if(nums[lo]<=target && nums[mid]>=target) //check if element lies in left half or not
                hi=mid-1;
                else
                lo=mid+1;
            }
            else{
                if(nums[mid]<=nums[hi]){
                    if(nums[mid]<=target && nums[hi]>=target)
                    lo=mid+1;
                    else
                    hi=mid-1;
                }
            }


        }
        return -1;
    }
};
