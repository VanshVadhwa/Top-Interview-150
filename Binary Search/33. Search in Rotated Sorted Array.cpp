class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[0]) {
                if(target <= nums[mid] && target >= nums[0]) end=mid-1;
                else start = mid+1;
            }
            else {
                if(target>=nums[mid] && target <= nums[n-1]) start = mid+1;
                else end = mid-1;
            }
        }

        return -1;
    }
};
