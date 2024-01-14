class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> v;
        string word;//to store wrods of string s
        stringstream ss(s);//breaks string into words
        //push words into vectors
        while(ss >> word){
            v.push_back(word);
        }

        set<string> S;//to check if the same word is not mapped to another char
        //edge case
        if(pattern.size() != v.size())
            return false;

        unordered_map<char, string> mp;
        for(int i=0; i<pattern.size(); i++){
            char ch = pattern[i];
            //if current char is in the map
            if(mp.find(ch) != mp.end()){
                //check if string mapped to that char is different or not
                if(mp[ch] != v[i])
                    return false;
            }
            else{
                //check if string is previously in set
                //if present it means it is already mapped return false
                if(S.count(v[i]) > 0)
                    return false;
                //otherwise insert into map and set
                mp[ch] = v[i];
                S.insert(v[i]);
            }
        }
        return true;
    }
};

//Tc and SC - O(N)
