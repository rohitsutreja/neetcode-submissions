class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;

        for (const auto& str : strs) {
            string key(26, '\0'); 
            for (const auto ch : str) {
                key[ch - 'a']++;
            }
            
            result[key].push_back(str);
        }

        vector<vector<string>> r;
        r.reserve(result.size());

        for (auto& [hash, vec] : result) {
            r.push_back(std::move(vec)); 
        }

        return r;
    }
};