class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int ans = 0;
        unordered_map<char,int> map;
        for(int right=0;right<n;right++) {
            if(map.find(s[right]) != map.end()) {
                left = max(left,map[s[right]]+1);
            }
            ans = max(ans,right-left+1);
            map[s[right]] = right; 
        }
        return ans;
    }
};
