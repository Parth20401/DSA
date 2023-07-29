lass Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].length();i++){
          char ch=strs[0][i];   //i'th character of 1st string

            bool match=true;
        for(int j=1;j<strs.size();j++){ //for comparing 1st string to all other strings

        if(strs[j].size()<i || ch!=strs[j][i]){
            match=false;
            break;
        }
        }
        if(match==false)
        break;
        else
        ans.push_back(ch);
        }
        return ans;
    }
};
