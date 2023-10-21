class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> result;
        int n = digits.size();

        for(int i=n-1; i>=0; i--){
            int sum = digits[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }

        //if carry left
        if(carry > 0)
            result.push_back(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};
