class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for(const auto n : nums){
            if(count == 0){
                candidate = n;    
            }

            if(n == candidate){
                count++;
            }
            else{
                count--;
            }


        }

        return candidate;
    }
};