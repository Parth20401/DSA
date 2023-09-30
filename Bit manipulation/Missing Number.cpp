class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int res = nums.size();
       int i = 0;

       for(int num : nums){
           res ^= num;
           res ^= i; //XORing any no with 0 gives that no back
           i++;
       } 
       return res;
    }
};
