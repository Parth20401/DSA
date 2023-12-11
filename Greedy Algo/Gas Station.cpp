class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0;
        int totalGas = 0;

        for(int i=0; i<gas.size(); i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost > totalGas)//if true, means we cannot make circle
            return -1;

        int total = 0;
        int ans = 0;

        for(int i=0; i<gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};
