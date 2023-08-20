class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;

        for(int i=0; i<s.length(); i++){
            count[s[i]]++;  //store count of all characters
        }
        int result = 0;
        bool odd_found = false;
        for(auto& c:count){
            if(c.second % 2 == 0)  result += c.second;  //we simply add all even count 
            else{
                 //there can be many odd char, but we take only one occurence as only one odd char can come in middle
                odd_found = true;
                result += c.second - 1;  //we add all odd counts-1 to make it even
            }
        }
        if(odd_found) //if odd_found is true, then add 1(to make up for extra odd char)
            result += 1;
        return result;
    }
};
