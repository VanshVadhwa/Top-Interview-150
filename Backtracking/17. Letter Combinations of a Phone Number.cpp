class Solution {
private:
    void generate(string digits, int index, string& temp, vector<string>& ans, vector<string>& mapping)
    {
        if(index==digits.length()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index]-'0';
        string value = mapping[digit];

        for(int i=0;i<value.length();i++) {
            temp.push_back(value[i]);
            generate(digits,index+1,temp,ans,mapping);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        vector<string> ans;
        generate(digits,0,temp,ans,arr);
        return ans;
    }
};
