class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;

        int candies = 1;
        int up = 1, down = 0, peak = 0;

        for(int i=1;i<n;i++) {
            if(ratings[i] > ratings[i-1]) {
                candies += ++up;
                peak = up;
                down = 0;
            }
            else if(ratings[i] < ratings[i-1]) {
                candies += ++down;
                up = 1;
                if(down >= peak) candies++;
            }
            else {
                up = 1;
                down = 0;
                peak = 1;
                candies += 1;
            }
        }

        return candies;
    }
};
