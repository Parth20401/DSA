class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        //vector<string> s1;
        for(int i=0;i<operations.size();i++){
            if((operations[i]=="--X") || (operations[i]=="X--"))
            x--;
            if((operations[i]=="++X" ) || (operations[i]=="X++"))
            x++;
        }
        return x;
    }
};
