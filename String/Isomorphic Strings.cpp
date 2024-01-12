class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //we solve the problem thinking that mapping should be done on bot the sides eg-> for egg, add : e->a and a->e and so on
        unordered_map<char, vector<int>> m1;
        unordered_map<char, vector<int>> m2;

        for(int i=0; i<s.length(); i++){
            m1[s[i]].push_back(i);
             m2[t[i]].push_back(i);

            if(m1[s[i]] != m2[t[i]]) //checks if both vectors are equal or not
                return false;
        }
        return true;
    }
};
