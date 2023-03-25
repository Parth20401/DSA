
class Solution {
public:
    bool canSplit(vector<int>& nums,int mid,int k){
        int subArrayCount=0;
        int currSum=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]+currSum>mid){
                subArrayCount++;
                currSum=0;
            }
            currSum+=nums[i];
        }
            return subArrayCount+1<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0,e=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            s=max(s,nums[i]);
            e+=nums[i];
        }
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(canSplit(nums,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};
