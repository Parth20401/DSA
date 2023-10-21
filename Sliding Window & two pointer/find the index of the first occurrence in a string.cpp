class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        int nIndex = 0;

        //we solve using sliding window
        for(int i=0; i<hLen; i++){
            // as long as the characters are equal, increment needleIndex
            if(haystack[i] == needle[nIndex]){
                nIndex++;
            }
            else{
                // start from the next index of previous start index
                i = i - nIndex;
                //nIndex to be set to 0 again
                nIndex = 0;
            }

            if(nIndex == nLen)
                return i - nLen + 1;//return the first occuring index
        }
        return -1;
    }
};
