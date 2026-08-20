class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count{};

        for(const auto& str: details){
            auto tens{str[11] - '0'};
            auto zeros{str[12] - '0'};

            auto age = tens * 10 + zeros;
            
            if(age > 60){
                count++;
            }
        }

        return count;
    }
};