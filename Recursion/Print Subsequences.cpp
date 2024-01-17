void solve(string s, int len, vector<string>& ans, string output, int idx){
    //base case
    if(idx == len){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(s, len, ans, output, idx + 1);

    //include
    char x = s[idx];
    output = output + x;
    solve(s, len, ans, output, idx + 1);
}

vector<string> generateSubsequences(string s)
{
    int len = s.length();
    vector<string> ans;
    solve(s, len, ans, "", 0);
    return ans;
}
//TC - O(2^len)
//SC - O(len)
