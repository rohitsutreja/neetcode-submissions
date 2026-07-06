class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIdx{};

        for(int i{}; i < nums.size(); ++i){
            const auto complement{target - nums[i]};

            if(const auto found{valToIdx.find(complement)}; found != valToIdx.end()){
                return {found->second, i};
            }

            valToIdx[nums[i]] = i;
        }

        return {};
    }
};
