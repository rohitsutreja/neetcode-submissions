class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul{1};
        int zeros{};

        for(const int num : nums){
            if(num != 0){
                mul *= num;
            }
            else{
                zeros++;
            }
        }

        vector<int> result(nums.size());

        for(int i{}; i < nums.size(); ++i){
            if(nums[i] == 0){
                if(zeros < 2){
                    result[i] = mul;
                }
                else {
                    result[i] = 0;
                }
            }
            else{
                if(zeros > 0){
                    result[i] = 0;
                }else{
                    result[i] = mul / nums[i];
                }
            }
        }

        return result;
    }
};
