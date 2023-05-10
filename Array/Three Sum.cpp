class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        
        //move for a
        for(int i=0; i<nums.size()-2; i++){ // loop will run only till 3rd last element

        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){ //avoiding suplicates by skiiping consecutive elements

            int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i]; //b+c = -a (for sum)

            while(lo < hi){
                if(nums[lo] + nums[hi] == sum){ //means we have found a triplet

                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    ans.push_back(temp);

                    while(lo < hi && nums[lo] == nums[lo + 1])  lo++;//if there is duplicate element, then skip it and move lo forward
                    while(lo < hi && nums[hi] == nums[hi - 1])  hi--; //if there is duplicate element, then skip it and move hi back

                lo++; hi--; //after finding triplet, move both lo and hi forward and back respectively
                }

                else if(nums[lo] + nums[hi] < sum) 
                    lo++; //if sum is less, move lo forward
                else
                    hi--; //else move hi back
                }
            }
        }
        return ans;
    }
};
