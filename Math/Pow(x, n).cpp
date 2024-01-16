class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            x = 1 / x;

        long num = labs(n);
        double pow = 1;

        while(num != 0){
            //until the no is odd, keep multiplying
            if((num & 1) != 0) //eqivalent to n%2 != 0
                pow = pow * x;

            x *= x;
            num = num >> 1;//equivalent to n/2
        }

        return pow;
    }
};

//TC- O(log n)
//SC - O(1)
