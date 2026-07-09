class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result{nums[0]};
        int sum{};

        for(int i{}; i < nums.size(); ++i){
            sum += nums[i];
            result = max(result, sum);
            
            if(sum < 0){
                sum = 0;
            }
        }

        return result;
    }
};
