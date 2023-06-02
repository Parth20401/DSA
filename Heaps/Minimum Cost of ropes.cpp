class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long, vector<long long>, greater<long long> > pq; // min heap
       long long cost = 0;
       
       for(long long i=0; i<n; i++){
           pq.push(arr[i]);
       }
       
       while(pq.size() > 1){
           //take two smallest elements and add them .
           long long x1 = pq.top();
           pq.pop();
           long long x2 = pq.top();
           pq.pop();
           
           long long sum = x1 + x2;
           cost += sum;
           pq.push(sum);
       }
       return cost;
    }
};
