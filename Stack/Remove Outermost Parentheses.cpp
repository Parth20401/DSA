class Solution {
public:
    string removeOuterParentheses(string s) {
        stack <char>st;
        string x="";
        for(int i=0;i<s.length();i++){
          //  char ch=s.charAt[i];
            if(s[i]=='('){
                if(st.size()>0)
                {
                    x+=s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(st.size()>0){
                    x+=s[i];
                }
            }
        }
        return x;
    }
};
