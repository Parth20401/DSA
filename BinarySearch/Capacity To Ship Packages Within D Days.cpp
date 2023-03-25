class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int e=0;
        int mid;
        for(int i:weights){
            s=max(s,i);
            e+=i;
        }
        while(s<e){
            mid=s+(e-s)/2;
            int d=1,curr=0;
            for(int i:weights){

                if(curr+i>mid){
                    d++;
                    curr=0;
                }

                curr+=i;
            }
            if(d>days) s=mid+1;
            else e=mid;
           
        }
        return s;
    }
};
