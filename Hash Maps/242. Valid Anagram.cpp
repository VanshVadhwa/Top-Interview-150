class Solution {
public:
    bool isAnagram(string s, string t) {
        // as unicode characters can be used, so no freq(26) this time :(, but koina, aise bhi set hai :) :)
        if(s.size() != t.size()) return false;

        unordered_map<char,int> map;
        for(char c : s) map[c]++;
        for(char c : t) {
            if(map[c]==0) return false;
            map[c]--;
        }
        return true;
    }
};
