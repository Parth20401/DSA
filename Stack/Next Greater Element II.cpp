class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        nums.resize(2 * n);

        for(int i=n; i<2*n; i++){ //duplicate and concatenate the array
            nums[i] = nums[i - n];
        }

        stack<int> st;

        for(int i=0; i<2*n; i++){
            int curr = nums[i % n];//handling the circularity

            while(!st.empty() && nums[st.top()] < curr){
                
                ans[st.top()] = curr;
                st.pop();
            }

            if(i < n)
                st.push(i);
    }
    return ans;
    }
};
