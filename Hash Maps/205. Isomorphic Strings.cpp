class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> S_T;
        unordered_map<char,char> T_S;

        for(int i=0;i<s.length();i++) {
            if(S_T.count(s[i]) && S_T[s[i]] != t[i]) return false;
            if(T_S.count(t[i]) && T_S[t[i]] != s[i]) return false;

            S_T[s[i]] = t[i];
            T_S[t[i]] = s[i];
        }

        return true;
    }
};
