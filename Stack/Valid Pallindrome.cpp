class Solution {
public:
    bool isValid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            return 1;
            else
            return 0;

    }
    bool checkPallindrome(string a){
        int s=0;
        int e=a.length()-1;
        while(s<=e){

            if(a[s] != a[e])
            return false;
            else{
                s++; e--;
            }

        }
        return true;
    }
    bool isPalindrome(string s) {
        string x="";

        for(int i=0;i<s.length();i++){
            if(isValid(s[i])){
                x.push_back(tolower(s[i]));
            }

        }
        return checkPallindrome(x);
    }
};
