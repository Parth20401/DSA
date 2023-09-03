class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i<K; i++){
            pq.push({arr[i][0], {i, 0}}); //push the first element of each array into the pq
        }
        
        vector<int> res;
        while(!pq.empty()){
            int a = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            pq.pop();
            //checking if the elements of any particular array are exhausted
            if(j == K - 1){
                res.push_back(a);
                continue;
            }
            
            else{
            res.push_back(a);
            j++;
            pq.push({arr[i][j], {i, j}});//pushing next element from that array
            }
        }
        
        return res;
    }
};
//TC - O(N log K)
//SC - O(K)
