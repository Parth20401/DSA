class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(char & ch:s){
            if(ans.size() && ch==ans.back()){
                ans.pop_back();
            }
            else
                ans.push_back(ch);
        }
        return ans;

    }
};
