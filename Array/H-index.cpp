class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size(), i;
        sort(citations.begin(), citations.end());

        for(i=1; i<=n; i++){
            if(i > citations[n - i])//if idx goes higher than count, means we have found the h index
                break;
        }
        return i-1;
    }
};
