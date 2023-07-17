class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0]; //assume first element to be min
        int max_profit = 0;

        for(int i=1; i<n; i++){
            int cost = prices[i] - mini; //the cost is what we get after (SP - CP) 
            max_profit = max(max_profit, cost);//maximinzing profit
            mini = min(mini, prices[i]); //update mini to get min price of buying
        }

        return max_profit;
    }
};
