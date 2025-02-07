class Solution {
private:
    void create(vector<int>& nums, vector<int>& a, vector<int>& b) {
        int index = 0, n = nums.size(), n1 = a.size(), n2 = b.size();
        int index1 = 0, index2 = 0;

        while(index1 < n1 || index2 < n2) {
            int num1 = index1 < n1 ? a[index1] : INT_MAX;
            int num2 = index2 < n2 ? b[index2] : INT_MAX;
            if(num1 <= num2) {
                nums[index++] = num1;
                index1++;
            }
            else {
                nums[index++] = num2;
                index2++;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> nums(n,0);
        create(nums,nums1,nums2);

        return n%2 != 0 ? nums[n/2] : double(nums[n/2-1]+nums[n/2])/2;
    }
};
