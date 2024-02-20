class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        while(columnNumber > 0){
            int offset = (columnNumber - 1) % 26;//to obtain what the current char is.
            ans.push_back(offset + 'A');
            columnNumber = (columnNumber - 1) / 26;//And we divide columnNumber-1 by 26, in preparation for the next loop.
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//TC - O(log n)
