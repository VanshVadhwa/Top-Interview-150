class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = 0;
        for(int i=0;i<n;i++) {
            if(count==0) {
                candidate = nums[i];
                count++;
            }
            else {
                if(candidate == nums[i]) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }
        return candidate;
    }
};
