class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;

        for(int i=0;i<n;i++) {
            if(map.count(nums[i]) && abs(map[nums[i]]-i) <= k) {
                return true;
            }
            map[nums[i]] = i;
        }

        return false;
    }
};
