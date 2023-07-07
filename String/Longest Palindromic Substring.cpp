class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string ans;
        int ansLength = 0;

        //check for pallindrome for every character by checking it's left and right characters, if they are equal, it is pallindrome
        for(int i=0; i<len; i++){
        //odd length
        int l = i;
        int r = i;

        while(l >= 0 && r < len && s[l] == s[r]){
            if((r - l + 1) > ansLength){
                ans = s.substr(l, r - l + 1); //taking the string
                ansLength = r - l + 1;
            }
            //expand from i'th character towards left and right
            l--;
            r++;
        }

        //even length
        l = i;
        r = i + 1;

        while(l >= 0 && r < len && s[l] == s[r]){
            if((r - l + 1) > ansLength){
                ans = s.substr(l, r - l + 1); //taking the string
                ansLength = r - l + 1;
            }
            //expand from i'th character towards left and right
            l--;
            r++;
        }
    }
    return ans;
  }
};
