class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{prices.front()};
        int maxP{};

        for(int i{1}; i < prices.size(); ++i){
            maxP = max(prices[i] - min, maxP);
            min = std::min(prices[i], min);
        }

        return maxP;
    }
};
