class Solution {
private:
    int solve(char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0;i<n-1;i++) {
            ans = (solve(s[i]) < solve(s[i+1])) ? ans - solve(s[i]) : ans + solve(s[i]); 
        }

        return ans+solve(s[n-1]);
    }
};
