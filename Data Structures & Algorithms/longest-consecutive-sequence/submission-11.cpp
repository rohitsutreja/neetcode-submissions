class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s{nums.begin(), nums.end()};
        int result{};

        for(const int num : nums ){
            if(!s.contains(num - 1)){
                int start = num;
                int cur{0};
                while(s.contains(start++)){
                    cur++;
                    result = max(cur, result);
                };
            }
        }

        return result;
    }
};
