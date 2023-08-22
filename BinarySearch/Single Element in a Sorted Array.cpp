class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int n = nums.size();
        //we do so many checks as we don't want binary search to be complicated
        if(n == 1)  return nums[0];
        if(arr[0] != arr[1])    return arr[0];
        if(arr[n - 1] != arr[n - 2])    return arr[n - 1];

        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            
            else if((nums[mid]==nums[mid+1] && mid%2==0) || (nums[mid]==nums[mid-1] && mid%2!=0))
            //if true, means we are in left half and req number is in right half
                s=mid+1;
            else
                e=mid-1; 
        }
        return -1;
    }
};
