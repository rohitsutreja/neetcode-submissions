class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i{};
        int j{static_cast<int>(strs[0].size())};

        for(int i{}; i < j; ++i){
            for(const auto& str: strs){
                if(str[i] != strs[0][i]){
                    j = i;
                }
            }
        }

        return strs[0].substr(0, j);
    }
};