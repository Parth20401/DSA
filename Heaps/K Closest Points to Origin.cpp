class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;

        for(auto& i : points){
            int x = i[0], y = i[1]; //storing coordinates
            maxHeap.push({x*x + y*y, x, y});
            //remove (n-k) elements and only keep k smallest elements
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans(k);
        for(int i=0; i<k; i++){
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            ans[i] = {top[1], top[2]};
        }
        return ans;
    }
};
