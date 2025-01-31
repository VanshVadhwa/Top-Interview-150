class Solution {
private:
    void comb(int n, int start, int k, vector<int>& temp, vector<vector<int>>& ans)
    {
        // base case
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        
        for(int num=start;num<=n;num++) {
            temp.push_back(num);
            comb(n,num+1,k,temp,ans);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        comb(n,1,k,temp,ans);
        return ans;
    }
};
