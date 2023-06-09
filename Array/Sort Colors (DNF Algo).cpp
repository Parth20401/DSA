class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0;
        int high = n - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++; mid++;
            }

            else if(nums[mid] == 1)
                mid++;

            //means we only have 2 to encounter
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
//This is DNF algo
//TC - O(N)
