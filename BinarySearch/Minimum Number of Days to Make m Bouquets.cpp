class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long int)m*k>bloomDay.size())  return -1;
        int s=1,e=1,mid;
        for(int i:bloomDay){
            s=min(s,i);
            e=max(e,i);
        }
        while(s<e){
            mid=s+(e-s)/2;
            if(CanMake(mid,m,k,bloomDay)){
                e=mid;
            }
            else
                s=mid+1;
        }

            return s;
    }

    bool CanMake(int mid,int m,int k,vector<int>&bloomDay)
    {
        int count=0;
        for(int i:bloomDay){
            if(i<=mid)
            {
                count++;
                if(count==k){
                    m--;
                    count=0;
                    if(m==0)  return true;
                }
            }
            else count=0;
        }
        return false;
    }
};
