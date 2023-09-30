lass Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                nums[j++]=nums[i];//if not zero, move that no to the starting
        }
        for(;j<nums.size();j++){
            nums[j]=0; //fill out the remaining plces with zero
        }
    }
};
