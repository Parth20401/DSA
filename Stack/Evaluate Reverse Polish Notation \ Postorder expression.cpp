class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st; //to keep the operands
        for(auto i: tokens){
            if(i.size() > 1 || isdigit(i[0]))
                st.push(stoi(i)); //if a number is found, push in stack as a number
            //we go to else if we found operator,that means pull two operands from stack and apply the operator
            else{
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                switch(i[0]){
                    case '+':
                    st.push(val2 + val1);
                    break;
                    case '-':
                    st.push(val2 - val1);
                    break;
                     case '*':
                    st.push(val2 * val1);
                    break;
                     case '/':
                    st.push(val2 / val1);
                    break;
                }
            }
        }
        return st.top();
    }
};
