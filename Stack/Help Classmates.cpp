class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            
            while(!st.empty() && st.top() >= curr)
                st.pop();//until we find a smaller element, keep popping
                
            if(!st.empty())
                ans[i] = st.top();
                
            else
                ans[i] = -1;
                
            st.push(curr);
        }
        return ans;
    } 
};
