class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, sum = 0;
        
        for(int  i : nums) {
            sum += i;
            ans = max(ans,sum);
            if(sum<0) sum = 0;
        }

        return ans;
    }
};
