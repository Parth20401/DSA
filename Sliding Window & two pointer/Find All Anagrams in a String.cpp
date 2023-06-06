class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26, 0); //array for storing freq of alphabets
        vector<int> phash(26, 0);
        int k = p.length();
        int len = s.length();
        int right = 0, left = 0;
        vector<int> ans;
        if(k > len)
            return ans;
        //mark freq of characters of hash and phash for 1st window 
        while(right < k){
            phash[p[right] - 'a']++;
            hash[s[right] - 'a']++;
            right++;
        }
        right--;
        //process further windows
        while(right < len){
            if(phash == hash)
                ans.push_back(left);
            right++;

            if(right != len)
                hash[s[right] - 'a']++; //adding new element to window
            hash[s[left] - 'a']--; //removing element from window 
            left++;
        }
        return ans;
    }
};
