class Solution {
public:
    bool search(int i, int j, int n, int m, vector<vector<char>>& board, string word, int k){
        //here k is the size current character.
        if(k == word.size())   return true; //means we have traversed and found the word

        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[k])  return false;

        //dealing with visiting same cell again
        char ch = board[i][j];
        board[i][j] = '#'; //marking the visited cell

        //now we traverse in 4 directions
        bool op1 = search(i + 1, j, n, m, board, word, k + 1);//k+1 means next word index for searching
        bool op2 = search(i, j + 1, n, m, board, word, k + 1);
        bool op3 = search(i - 1, j, n, m, board, word, k + 1);
        bool op4 = search(i, j - 1, n, m, board, word, k + 1);

        board[i][j] = ch; //so as to have no changes in the original matrix

        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //if we find the 1st letter, then start the search
                if(board[i][j] == word[0]){
                    if(search(i, j, n, m, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
