class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }

    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];

        int i = start;
        int j = end - 1;

        while(i <= j){
            while(nums[i] < pivot && i <= j){
                ++i;
            }

            while(nums[j] > pivot && i <= j){
                --j;
            }

            if(i <= j){
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }

        std::swap(nums[end], nums[i]);

        return i;
    }


    void quick(vector<int>& nums, int start,int end){
        if (start >= end) return;

        int mid = partition(nums, start, end);
        quick(nums, start, mid - 1);
        quick(nums, mid + 1, end);
    }
};