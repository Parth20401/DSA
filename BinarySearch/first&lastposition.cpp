class Solution {
public:
   
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int>v;
         int s=0;
        int e=nums.size()-1;
        int ans1=-1;
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==target){
            ans1=mid;
            e=mid-1;
            }
            else if(nums[mid]>target)
            e=mid-1;
            else
            s=mid+1;
            mid=s+(e-s)/2;
    }
    v.push_back(ans1);
    int s2=0;
        int e2=nums.size()-1;
        int ans2=-1;
        int mid2=s2+(e2-s2)/2;
        while(s2<=e2)
        {
            if(nums[mid2]==target){
            ans2=mid2;
            s2=mid2+1;
            }
            else if(nums[mid2]>target)
            e2=mid2-1;
            else if(nums[mid2]<target)
            s2=mid2+1;
            mid2=s2+(e2-s2)/2;
    }
    v.push_back(ans2);

    return v;


        }

    
};
