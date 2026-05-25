class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{};
        mp[0] = 1;

        int sum{};
        int res{};

        for(int i{}; i < nums.size(); ++i){
            sum += nums[i];

            if(mp.contains(sum - k)){
                res += mp[sum - k];
            }
            
            mp[sum]++;
        }

        return res;
    }
};