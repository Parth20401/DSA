class Solution {
private:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }

public:
    int myAtoi(string s) {
        const int len = s.size();

        if(len == 0)
            return 0;

            int index = 0;

            //skipping white spaces
            while(index < len && s[index] == ' ')
                index++;

            //handling signs
            bool isNegative = false;

            if(index < len){
                if(s[index] == '-'){
                    isNegative = true;
                    index++;
                }
                else if(s[index] == '+')
                    index++;
            }

            int result = 0;

            //convert char to digit
            while(index < len && isDigit(s[index])){
                int digit = s[index] - '0';

                //avoiding integer overflow
                if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
                    return isNegative ? INT_MIN : INT_MAX;
                }
                result = (result * 10) + digit; //adding digtis at their desired place value

                index++;
            } 
            return isNegative ? -result : result;
    }
};
