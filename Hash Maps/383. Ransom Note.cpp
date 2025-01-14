class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> marked(26,0);

        for(char c : magazine) {
            marked[c-'a']++;
        }

        for(char c : ransomNote) {
            if(marked[c-'a']==0) {
                return false;
            }
            marked[c-'a']--;
        }

        return true;
    }
};
