class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int result{1};
        int cur{1};

        std::ranges::sort(nums);
        for(int i{1}; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1] + 1){
                cur++;
                result = max(result, cur);
            }
            else if(nums[i] == nums[i - 1]){
                continue;
            }
            else{
                cur = 1;
            }
        }

        return result;
    }
};
