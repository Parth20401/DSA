class Solution {
public:
    string convert(string s, int numRows) {
        //edge case
        if(numRows == 1)
            return s;

        string ans = "";

        //now we go row by row
        for(int row=0; row<numRows; row++){
        //for each row the next char is at 2*(numRows - 1)
            int increment = 2 * (numRows - 1);

            //for 1st and last rows
            for(int i=row; i<s.length(); i+= increment){
                ans += s[i];

            //for middle rows, we calculate differently
            if(row > 0 && row < numRows - 1 && i + increment - 2 * row < s.length()){
                ans += s[i + increment - 2 * row];//as row no. dec, no of steps to reach next char dec
                }
            } 
        }
        return ans;
    }
};

//Tc - O(N)
//SC- O(1)
