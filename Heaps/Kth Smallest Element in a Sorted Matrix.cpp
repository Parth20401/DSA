class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        vector<int> v;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                v.push_back(matrix[i][j]);
            }
        }
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            pq.push(v[i]);
        }

        for(int i=k; i<v.size(); i++){
            if(v[i] < pq.top()){
                pq.pop();
                pq.push(v[i]);
            }
        }
        return pq.top();
    }
};
