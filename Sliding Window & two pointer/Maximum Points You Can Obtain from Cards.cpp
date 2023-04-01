class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        for(int i=0;i<k;i++)
            ans+=cardPoints[i];
        int curr=ans;
        //We remove the last visited element and add the non-visited element from the last
        for(int i=k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[(cardPoints.size()-k+i)];

            //checking maximum of all possible combinations
            ans=max(ans,curr);
        }
        return ans;
    }
};
