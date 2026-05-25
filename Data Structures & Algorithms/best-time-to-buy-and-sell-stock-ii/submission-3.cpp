class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> mem(prices.size(), vector<int>(2, -1));

        return rec(prices, 0, false, mem);
    }


    private:
    int rec(vector<int>& prices, int day, bool holding, vector<vector<int>>& dp){
        if(day == prices.size()){
            return 0;
        }

        if(dp[day][holding] != -1){
            return dp[day][holding];
        }


        if(holding){
            auto sell = prices[day] + rec(prices, day + 1, false, dp);
            auto skip = rec(prices, day + 1, true,dp);
            dp[day][holding] = max(skip, sell);
            return dp[day][holding];
        }

        auto buy =  -prices[day] + rec(prices, day + 1, true, dp);
        auto skip = rec(prices, day + 1, false, dp);
        dp[day][holding] = max(buy, skip);
        return dp[day][holding];
    }
};