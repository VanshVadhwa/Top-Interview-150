class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mini = *min_element(strs.begin(),strs.end());
        string maxi = *max_element(strs.begin(),strs.end());

        int index1 = 0, index2 = 0;
        while(index1 < mini.length() && index2 < maxi.length()) {
            if(mini[index1] != maxi[index2]) {
                return mini.substr(0,index1);
            }
            index1++,index2++;
        }

        return mini.substr(0,index1);
    }
};
