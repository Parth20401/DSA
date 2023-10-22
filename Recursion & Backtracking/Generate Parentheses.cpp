class Solution {
private:
    void generate(int n, int open, int close, string str, vector<string>& result){
        if(open == n && close == n){
            result.push_back(str);
            return;
        }
        //only add open parantheses if open < n
        if(open < n)
            generate(n, open + 1, close, str + '(', result);
        
        //only add close parantheses if open > close
        if(open > close)
            generate(n, open, close + 1, str + ')', result);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
};
