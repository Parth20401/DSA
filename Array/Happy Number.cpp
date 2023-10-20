class Solution {
public:
    int next (int n){
        int sum = 0;

        while(n != 0){
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));

        while(slow != fast){
            slow = next(slow); //move slow one step
            fast = next(next(fast));//move fast two steps at once
            }
            return (fast == 1);
        }
};
//TC - O(λ + μ)
