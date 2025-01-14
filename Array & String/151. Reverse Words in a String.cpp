class Solution {
public:
    string reverseWords(string s) {
        // O(1) space and Average = O(n) time
        int n = s.length();
        reverse(s.begin(),s.end());

        bool flag = false;
        int count = 0;

        int start = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        int i = 0; 
        for (int j = 0; j < n; ++j) {
            if (s[j] == ' ' && (i==0 || s[i-1] == ' ')) continue;
            s[i++] = s[j];
        }

        if (i > 0 && s[i - 1] == ' ') i--;
        s.resize(i);

        return s;
    }
};
