class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        int lF =  -1;
        int rf = -1;

        int mid = left + (right - left)/2;

        while(left <= right){
            mid = left + (right - left)/2;

            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }else{
                right = mid - 1;
                lF = mid;
            }
        }


        left = 0;
        right = nums.size() - 1;

        mid = left + (right - left)/2;

        while(left <= right){
            mid = left + (right - left)/2;

            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
                rf = mid;
            }
        }


        return {lF, rf};
    }
};