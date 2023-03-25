class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        auto small_or_equal=[&](int mid){
            int c=0;
            for(auto &num:nums){
                if(num<=mid)
                    c++;
            }
            return c;
};
        int low=1,high=nums.size();
        int f=-1;
        while(low<=high)
        {
            int mid=(high+low)/2;
            if(small_or_equal(mid)>mid)
            { 
                f=mid;
            high =mid-1;
            }    
            else
                low=mid+1;
        }
        return f;
    }
};
