class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto lcp = strs[0];

        for(const auto& str: strs){
            int i{};
            for(; i < std::min(lcp.size(), str.size()); ++i)
            {
                if(lcp[i] != str[i]){
                    lcp = lcp.substr(0, i);
                    break;
                }
            }

            lcp = lcp.substr(0,i);
        }

        return lcp;
    }
};