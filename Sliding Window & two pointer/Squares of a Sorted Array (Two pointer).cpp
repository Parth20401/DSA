class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        vector<int> ans(n);
        int pos = n - 1; //we will start inserting from last position

        while(s <= e){
            if(abs(nums[s]) < abs(nums[e])){
                ans[pos--] = nums[e] * nums[e];
                e--;
            }
            else{
                ans[pos--] = nums[s] * nums[s];
                s++;
            }
        }
        return ans; 
    }
};
