class Solution {
public:
    void reverse(vector<int>& nums, int s, int e){
        while(s < e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int p = -1;
        int pv = 0;

        //to get 1st number which is not in increasing order
        for(int i=n-1; i>=0; i--){
            if(nums[i + 1] > nums[i]){
                p = i;
                pv = nums[i];
                break;
            }
        }
        //if the number not found-> array in dec order, so reverse the array
        if(p == -1){
            reverse(nums, 0, n);
            return;
        }

        //if no. found, then swap with 1st largest no after it, and reverse the numbers after that number.
        for(int i=n; i>=0; i--){
            if(pv < nums[i]){
                swap(nums[p], nums[i]);
                break;
            }
        }
        reverse(nums, p + 1, n);
    }
};
