class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.length();
        int m = b.length();
        int i = 0;
        int carry = 0;

        while(i < n || i < m || carry != 0){
            int val1 = 0;
            if(i < n && a[n - i - 1] == '1') //n-i-1 bcos we add from right to left
                val1 = 1;

            int val2 = 0;
            if(i < m && b[m - i - 1] == '1')
                val2 = 1;

            res = to_string((val1 + val2 + carry) % 2) + res;//adding in reverse
            carry = (val1 + val2 + carry) / 2;//to get carry
            i++;
        }

        return res;
    }
};
