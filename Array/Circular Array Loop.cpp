class Solution {
public:
int next(vector<int>& nums, int i){ //here i is starting index
        int n = nums.size();
        return (n+nums[i]+i)%n; //to keep the index in range i.e, [0, n-1]
    } 
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        // we can use slow and fast pointer to check whether there is loop or not
        for(int &num: nums)
            num %= n; //to normalize the value of num

        for(int i=0;i<n;i++){
            int slow = i,
                fast = i;
                //check for potential loop by checking posiitve sign
            while(nums[slow] * nums[next(nums,fast)] > 0 && nums[slow] * nums[next(nums,next(nums,fast))] > 0){
                //update slow and fast
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
                if(slow==fast){
                    if(slow==next(nums,slow)) // single length i.e, not valid loop
                        return false;
                    return true;
                }
            }
			/// DONOT TRAVERSE WHERE THERE IS NO PATH TO GET LOOP.
            //or mark the visited elements as 0, to tell they are not a part of loop
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nexx = next(nums,j);
                nums[j] = 0;
                j = nexx;
            }
        }
        
        return false;
    }
};
