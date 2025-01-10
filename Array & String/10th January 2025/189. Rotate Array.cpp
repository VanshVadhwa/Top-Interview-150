class Solution {
private:
    void ro(vector<int>& nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++,end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        ro(nums,0,n-1);
        ro(nums,0,k-1);
        ro(nums,k,n-1);
    }
};
