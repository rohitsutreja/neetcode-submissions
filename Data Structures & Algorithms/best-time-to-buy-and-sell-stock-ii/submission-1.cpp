class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result{};

        int buy{0};

        for(int i {1}; i < prices.size(); ++i){
            if(prices[i] > prices[buy]){
                result += prices[i] - prices[buy];
            }
            buy = i;
        }


        return result;
    }
};