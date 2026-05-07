class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto lcp = strs[0];

        for(const auto& str: strs){
            for(int i{}; i < std::min(lcp.size(), str.size()); ++i)
            {
                if(lcp[i] != str[i]){
                    lcp = lcp.substr(0, i);
                    break;
                }
            }
            if(str.size() < lcp.size()){
                lcp = lcp.substr(0, str.size());
            }
        }

        return lcp;
    }
};