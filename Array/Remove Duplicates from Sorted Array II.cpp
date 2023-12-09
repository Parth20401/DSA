class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;

        for(auto ele : nums){
          //i == 0-> bcos 1st entry always icluded
          //i == 1-> 2nd element included
          //nums[i-2] != ele-> check if current element is not same as the one two positions BEFORE current position. This ensures only two occurances of an element
            if(i == 0 || i == 1 || nums[i - 2] != ele){
                nums[i] = ele;
                i++;
            }
        }
        return i;
    }
};
