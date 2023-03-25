//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
                st.push(ch);
                
            else{
                //we come here when ch is either closed bracket or lowercase letter
                if(ch==')'){
                    bool isRedundant=true;
                    char top=st.top();
                    while(st.top()!='('){
                        if(top=='+' || top=='-' || top=='*' || top=='/')
                            isRedundant=false;
                        st.pop();
                }
            if(isRedundant==true)
                return 1;
            st.pop();
            }
        }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
