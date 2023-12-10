class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size(), i;
        sort(citations.begin(), citations.end(), greater<int>());
        int ans = 0;

        for(i=1; i<=n; i++){
            if(citations[i - 1] < i) 
                break;
            ans = i;
        }
        return ans;
    }
};
