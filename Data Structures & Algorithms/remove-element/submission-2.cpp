class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        int read = 0;

        while(read < nums.size()){
            if(nums[read] != val){
                nums[write++] = nums[read];
            }

            ++read;
        }

        return write;
    }
};