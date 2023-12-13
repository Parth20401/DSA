class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.length();
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ')
                i++;
            
            if(i >= n)  break;

            int j = i + 1;
            while(j < n && s[j] != ' ')
                j++;

            string sub = s.substr(i, j - i);//take the first word out by using i & j variable

            if(ans.length() == 0)
                ans = sub;
            else
                ans = sub + " " + ans;
            
            i = j + 1;//assigning i as j+1 for the next word
        }
        return ans;
    }
};
