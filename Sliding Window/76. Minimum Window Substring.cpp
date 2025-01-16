class Solution {
public:
    string minWindow(string s, string t) {
        int tLen = t.length();
        int sLen = s.length();
        if(sLen < tLen) return "";

        unordered_map<char,int> tMap;
        for(char c : t) tMap[c]++;

        unordered_map<char,int> sMap;
        int size = INT_MAX, count = 0;
        int left = 0, leftIndex = 0;

        for(int right=0;right<sLen;right++) 
        {
            sMap[s[right]]++;
            if(sMap[s[right]]==tMap[s[right]]) 
                count += tMap[s[right]];
            
            while(count>=tLen && left <= right) {
                if(right-left+1 < size) {
                    size = right-left+1;
                    leftIndex = left;
                }
                sMap[s[left]]--;
                if(sMap[s[left]] < tMap[s[left]]) {
                    count-=tMap[s[left]];
                }
                left++;
            }
        }

        return size==INT_MAX ? "" : s.substr(leftIndex,size);

    }
};
