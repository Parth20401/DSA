class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        
        for(int i=0; i<piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    double calculateTotalHours(vector<int>& piles, int hourly){
        double totalH = 0;

        for(int i=0; i<piles.size(); i++){
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = findMax(piles);

        while(lo <= hi){
            int mid = (lo + hi)/2;
            double totalHours = calculateTotalHours(piles, mid);//find the hours it takes to eat a particular pile
            if(totalHours <= h)//if true, means possible answer, so move back
                hi = mid - 1; 
            else
                lo = mid + 1;
        }
        return lo;
    }
};
