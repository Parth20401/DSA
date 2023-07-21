vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    int N = A.size();
    vector<int> freq(N + 1, 0); // Initialize the frequency array with size N+1 and all elements as 0

    for (int i = 0; i < N; i++) {
        freq[A[i]]++;
    }

    int repeated = -1;
    int missing = -1;

    for (int i = 1; i <= N; i++) {
        if (freq[i] == 0) {
            missing = i;
        } else if (freq[i] == 2) {
            repeated = i;
        }
    }

    ans.push_back(repeated);
    ans.push_back(missing);
    return ans;
}
//when there is large input, do not use map, instead use frequency array.
