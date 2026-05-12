class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        result[0] = 1;

        for(int i{1}; i < nums.size(); ++i){
            result[i] = result[i - 1] * nums[i - 1];
        }

        int temp{1};

        for(int i{static_cast<int>(nums.size()) - 2}; i >= 0; --i){
            temp = temp * nums[i + 1];
            result[i] = temp * result[i];
        }

        return result;
    }
};
