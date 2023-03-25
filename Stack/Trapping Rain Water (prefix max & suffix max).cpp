class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2)
            return 0;
            int maxl[n];
            int maxr[n];
            maxl[0]=height[0];
            maxr[n-1]=height[n-1];
            //prefix max
        for(int i=1;i<n;i++){
            maxl[i]=max(maxl[i-1],height[i]);
        }
        //suffix max
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],height[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int l=maxl[i-1];
            int r=maxr[i+1];
            int diff=min(l,r)-height[i];
            if(diff>0)
                ans+=diff;
        }
            return ans; 
    }
};
