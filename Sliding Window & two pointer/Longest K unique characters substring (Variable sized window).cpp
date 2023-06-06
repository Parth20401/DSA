class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> mp;
        int maxi = -1;
        int j = 0, i = 0;
        
        while(j < s.length()){
            mp[s[j]]++;
            
        if(mp.size() < k)
            j++;
        //if we find k unique characters   
        else if(mp.size() == k){
        maxi = max(maxi, j - i + 1);//j-i+1 is size of window
        j++;
        }
         //there are more than k unique chaeracters
        else if (mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;
                //if the value becomes 0, then remove the key
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                    
                i++;
                }
             j++;
            }
        }
        return maxi;
    }
};
