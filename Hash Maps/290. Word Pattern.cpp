class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int p = pattern.size();
        int n = s.size();

        unordered_map<char,string> C_S;
        unordered_map<string,char> S_C;

        int j=0;
        for(int i=0;i<p;i++) {
            if(j >= n) return false;

            int t = j;
            while(j<n && s[j] != ' ') {
                j++;
            }

            char c = pattern[i];
            string word = s.substr(t,j-t);

            if(C_S.count(c) && C_S[c] != word) return false;
            if(S_C.count(word) && S_C[word] != c) return false;

            C_S[c] = word;
            S_C[word] = c;

            j++;
        }

        return j >= n;
    }
};
