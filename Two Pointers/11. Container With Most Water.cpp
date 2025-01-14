class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n-1;

        while(left <= right) {
            ans = max(min(height[left],height[right])*(right-left),ans);
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};
