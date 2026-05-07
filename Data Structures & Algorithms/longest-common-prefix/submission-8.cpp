class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string_view lcp{strs[0]};

        for(const auto& str: strs){
            int j{};

            while(j < min(str.size(), lcp.size()) && lcp[j] == str[j]){
                ++j;
            }

            lcp = lcp.substr(0, j);
        }

        return string{lcp};
    }
};