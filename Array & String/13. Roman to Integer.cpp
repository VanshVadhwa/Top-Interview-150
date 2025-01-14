class Solution {
private:
    int convert(char c) {
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        else 
        return 1000;
    }
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0;i<n-1;i++) {
            int first = convert(s[i]), second = convert(s[i+1]);
            ans = (first >= second) ? ans + first : ans - first;
        }

        ans += convert(s[n-1]);

        return ans;
    }
};
