class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1, str2;
        int l1 = s.length();
        int l2 = t.length();
        stack <char> s1, s2;

        for(int i=0; i<l1; i++){
            if(s[i] == '#' && !s1.empty())
                s1.pop();
            else if(s[i] != '#')
                s1.push(s[i]);
        }

       for(int i=0; i<l2; i++){
            if(t[i] == '#' && !s2.empty())
                s2.pop();
            else if(t[i] != '#')
                s2.push(t[i]);
        }

        while(!s1.empty()){
            str1.push_back(s1.top());
            s1.pop();
        }

        while(!s2.empty()){
            str2.push_back(s2.top());
            s2.pop();
        }

        return str1 == str2;
    }
};
