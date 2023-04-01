class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int>mp;
      int i=0,j=0;
      int ans=-1;
      int maxi=0;

      while(j<s.length()){
          mp[s[j]]++;
          maxi=max(maxi,mp[s[j]]);
          while((j-i+1)-maxi > k){ 
              mp[s[i]]--;
              i++;
          }
          ans=max(ans,j-i+1);
          j++;
      }  
      return ans;
    }
};
