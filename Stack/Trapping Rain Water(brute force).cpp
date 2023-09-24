class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int j = i;
            int leftMax = 0, rightMax = 0;
        //finding left max
        while(j >= 0){
            leftMax = max(leftMax, height[j]);//move from i towards 0
            j--;
            }

            j = i;
            //fidning right max
            while(j < n){
                rightMax = max(rightMax, height[j]);
                j++;
            }

            ans += min(leftMax, rightMax) - height[i];
        }

        return ans;
    }
};
