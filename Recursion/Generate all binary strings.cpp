void solve(int N, vector<string>& ans, string output, int idx){
    //base case
    if (idx == N) {
      ans.push_back(output);
      return;
    }

    //adding 0
    solve(N, ans, output + '0', idx + 1);

    //adding 1
    if((idx == 0) || (output[idx - 1] != '1'))
        solve(N, ans, output + '1', idx + 1);
        
}

vector<string> generateString(int N) {
    vector<string> ans;
    solve(N, ans, "", 0);
    return ans;
}
//Tc - O(2^N)
//SC - O(N)
