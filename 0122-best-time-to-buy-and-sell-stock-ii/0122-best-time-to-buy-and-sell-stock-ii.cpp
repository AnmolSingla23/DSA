class Solution {
public:
     //will hit tle as time is 2n
    int recursion(vector<int> &prices,int index,int buy){

        if(index == prices.size())
            return 0;

        int profit = 0;

        if(buy){
            profit = max(-prices[index] + recursion(prices,index+1,0), 0 + 
                                            recursion(prices,index+1,1));
        }  //subtracting as we are buying so we are down by that amount
        else{
            profit = max(prices[index] + recursion(prices,index+1,1), 0 + 
                                            recursion(prices,index+1,0));
        }
        return profit;
    }


    int memo(vector<int> &prices,int index ,vector<vector<int>> &dp,int buy){

        if(index == prices.size())
            return 0;
        
        int profit = 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
             profit = max(-prices[index] + memo(prices,index+1,dp,0), 0 + 
                                            memo(prices,index+1,dp,1));
        }
        else{
          profit = max(prices[index] + memo(prices,index+1,dp,1), 0 + 
                                            memo(prices,index+1,dp,0));
        }
        return dp[index][buy] = profit;
    }


    int tabu(vector<int> &prices){

        vector<vector<int> >dp(prices.size()+1,vector<int> (2,0));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;  //base case

        for(int index = prices.size()-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                 int profit = 0;

                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                }
                else{
                    profit = max(prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }


    //SPACE OPTIMIZATION
    int space(vector<int> &prices){

        vector<int> curr(2,0);
        vector<int> next(2,0);

        next[0] = next[1] = 0;  //base case

        for(int index = prices.size()-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                 int profit = 0;

                if(buy){
                    profit = max(-prices[index] + next[0], 0 + next[1]);
                }
                else{
                    profit = max(prices[index] + next[1], 0 + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
      
    //   int buy = 1;
    //   return recursion(prices,0,buy); //buy is bool to see if we are buying or selling  1 is buy and 0 is sell

    // vector<vector<int> >dp(prices.size(),vector<int> (2,-1));
    // return memo(prices,0,dp,1);

    // return tabu(prices);
        return space(prices);

    }
};