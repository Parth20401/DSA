class Solution {
public:
    //fn to check if bouquet can be made on that particular day
    bool isPossible(vector<int>& bloomDay, int day, int m, int k){
        int noOfBouquets = 0;
        int count = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day)
                count++;

            //if we come here, means we have encountered non bloom flower, so we check if we can make a bouquet from the flowers we got
            else{
                noOfBouquets += count/k;
                count = 0;
            }
        }

        noOfBouquets += count/k; //adding the remaining flowers

        if(noOfBouquets >= m)
            return true;
        else
            return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if((long long int)m*k > n)   return -1;
        int lo = 1;
        int hi = 1;

        //finding the range for binary search
        for(int i=0; i<n; i++){
            lo = min(lo, bloomDay[i]);
            hi = max(hi, bloomDay[i]);
        }

        while(lo < hi){
            int mid = (lo + hi)/2;

            if(isPossible(bloomDay, mid, m, k)) //if true, then possible ans found, so go further lower
                hi = mid;
            
            else 
                lo = mid + 1;
        }
        return lo;
    }
};
