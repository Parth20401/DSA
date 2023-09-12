class Solution {
public:

    int findDays(vector<int>& weights, int capacity, int days){
        int load = 0;
        int d = 1;

        for(int i=0; i<weights.size(); i++){
        //if while loading, the weights exceed the cpacity, then go to another day with that same load as before
            if(load + weights[i] > capacity){
                d++;
                load = weights[i];//bcos this weight was not added so added to the next day
            }
            else{
                load += weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            int noOfDays = findDays(weights, mid, days);
            if(noOfDays <= days)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
