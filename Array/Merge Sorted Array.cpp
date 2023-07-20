class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0){
            //fill out the greater values from behind
            if(nums1[i] < nums2[j]){
                 nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];
            }
        }

        //if A[m-1]>B[n-1], then A will replace the 0s (or maybe A has only single element [0]). so this loop replaces initial members of A with elements of B.
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
