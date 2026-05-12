class Solution {
public:

    string encode(vector<string>& strs) {
        string result{};

        for(const auto& str: strs){
            const auto len = str.length();
            result += to_string(len) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {   
        vector<string> result{};
        
        int i{};

        while(i < s.length()){

            int lenCount{};
            while(s[i] != '#'){
                ++i;
                ++lenCount;
            }

            auto len = std::stoi(s.substr(i - lenCount, lenCount));

            result.push_back(s.substr(++i, len));

            i = i + len;
        }

        return result;
    }
};
