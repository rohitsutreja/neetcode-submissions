class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }

    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];

        int write = start;
        
        for(int read = start; read < end; ++read){
            if(nums[read] <= pivot){
                std::swap(nums[write], nums[read]);
                write++;
            }
        }   

        std::swap(nums[write], nums[end]);

        return write;
    }


    void quick(vector<int>& nums, int start,int end){
        if (start >= end) return;

        int mid = partition(nums, start, end);
        quick(nums, start, mid - 1);
        quick(nums, mid + 1, end);
    }
};