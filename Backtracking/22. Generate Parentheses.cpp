class Solution {
private:
    void gen(int n, int left, int right, string& temp, vector<string>& ans) {
        if(right==n) {
            ans.push_back(temp);
            return;
        }

        if(left < n) {
            temp.push_back('(');
            gen(n,left+1,right,temp,ans);
            temp.pop_back();
        }

        if(right<left) {
            temp.push_back(')');
            gen(n,left,right+1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        gen(n,0,0,temp,ans);
        return ans;
    }
};
