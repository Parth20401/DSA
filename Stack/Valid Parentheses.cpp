class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            switch(ch){
                case '(':
                case '{':
                case '[':
                    st.push(ch);
                    break;

                case ')':
                 if(st.empty()==false && '('==st.top())
                        st.pop();
                  else  return false;      
                    break;
                case '}':
                 if(st.empty()==false && '{'==st.top())
                        st.pop();
                else    return false;
                    break;
                case ']':
                    if(st.empty()==false &&'['==st.top())
                        st.pop();
                    else  return false;
                    break;

            }
        }   
            return st.empty();
        
    }
};
