class Solution {
public:
    int firstBadVersion(int n) {
        int s = 0;
        int e = n;
        while(s<e){
            int mid = s + (e-s)/2;

            if(isBadVersion(mid)) 
                e = mid;  //if mid is bad, then lower versions can also be bad, so we go to left side
            else
                s = mid + 1; //if mid is not bad, we go to right side
        }
        return s;
    }
};
