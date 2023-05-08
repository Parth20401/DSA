
int longestSubstrDistinctChars (string S)
{
    vector<int> mp(256, -1);  //character array for characters and their indexes
    int left = 0, right = 0;
    int n = S.length();
    int len = 0;
    
    while(right < n){
        if(mp[S[right]] != -1)  //if character at right exists
            left = max(mp[S[right]] + 1, left); //update left if same character(already in the window) encountered
            
            mp[S[right]] = right; //update the indexes if same character encontered again
            
            len = max(len, right - left + 1);
            right ++;
    }
    return len;
}
