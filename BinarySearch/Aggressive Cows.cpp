class Solution {
public:

    bool canWePlace(vector<int> &stalls, int dist, int k){
        int cowCount = 1;
        int lastPos = stalls[0]; //to keep track of last stall where a cow was placed
        
        //we check if cow can be placed by taking min dist i.e.1 and then keep inc it
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - lastPos >= dist){
                cowCount++;
                lastPos = stalls[i];
            }
            if(cowCount >= k)   return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
        int lo = 1;
        int hi = stalls[n - 1] - stalls[0];

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            //if we can place at dist 'mid', look for a higher dist
            if(canWePlace(stalls, mid, k) == true)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return hi;
    }
};

//TC - O(log(max - min) of array) * O(N) + O(n log n)
