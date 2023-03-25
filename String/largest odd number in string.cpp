class Solution {
public:
    string largestOddNumber(string num) {
        string result="";
        for(int i=num.length();i>=0;i--){
            int isOdd=num[i]-'0';
            if(isOdd%2!=0){
                result=num.substr(0,i+1);
                break;
            }
        }
        return result;
    }
};
