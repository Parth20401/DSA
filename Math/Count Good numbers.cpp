#define ll long long

class Solution {
public:
    int p = 1e9 + 7;
    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7 => 4 primes

    ll power(ll x, ll y){
        ll res = 1;

        x = x % p;//update x if x>=p
        if(x == 0)
            return 0;

        while(y > 0){
            if(y & 1)
                res = (res * x) % p;//if odd, keep multiplying

            //update x and y
            // we have did the odd step is it was odd, now do the even step
            x = (x * x) % p;
            y = y >> 1;//dividing y by 2, y>>1 is same as y/2
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll count_of_4s = n / 2;
        ll count_of_5s = n - count_of_4s;

        ll ans = ((power(4LL, count_of_4s) % p * power(5LL, count_of_5s) % p) % p);
        return (int)ans;
    }
};

//TC - O(log n)
