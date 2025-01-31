class Solution {
private:
    void per(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            per(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        per(nums,0,ans);
        return ans;
    }
};
