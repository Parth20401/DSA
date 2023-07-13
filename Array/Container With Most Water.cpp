class Solution {
public:
    int maxArea(vector<int>& height) {
        //uaing two pointer approach
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while(left < right){
            int area = (right - left) * min(height[left], height[right]);
            ans = max(area, ans);
         //increament left ptr if it is smaller
            if(height[left] < height[right])  
                left++;
            else
                right--;
        }
        return ans;
    }
};
