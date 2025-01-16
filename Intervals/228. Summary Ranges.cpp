class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        for(int i=0;i<n;i++) {
            int j = i;
            while(i<n-1 && nums[i]+1==nums[i+1]) {
                i++;
            }
            if(i != j) ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
            else ans.push_back(to_string(nums[i]));
        }

        return ans;
    }
};
