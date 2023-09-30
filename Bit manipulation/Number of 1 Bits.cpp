class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0){
            
            if(n % 2 != 0)
                ans++;

            n = n >> 1;//bitwise shift to right to get the next digit
        }
        return ans;
    }
};
