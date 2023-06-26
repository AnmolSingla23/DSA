class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int mini = INT_MAX;  //this helps to calculate the minimum element 
        
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);  //finds the current minimum element
            profit = max(profit,prices[i] - mini);  //finds the max profit we can get from current price 
        }
        return profit;
    }
};