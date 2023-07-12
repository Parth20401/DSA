class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> st;
        st.push(-1);
        vector<long long> ans(n);
        
        for(int i=n-1; i>=0; i--){
        long long int curr = arr[i];
        //when we encounter a larger element in array, we need to pop from stack until larger element is found in the stack
        while(!st.empty() && st.top() <= curr){
            st.pop();
        }
        
        if(st.empty() == false)
            ans[i] = st.top();
        else
            ans[i] = -1;
            
        st.push(curr);
    }
    return ans;
 }
};
