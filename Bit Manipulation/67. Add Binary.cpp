class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int index1 = a.length()-1, index2 = b.length()-1;
        int sum = 0;

        while(index1 >= 0 || index2 >= 0 || sum) {
            int num1 = (index1 >= 0) ? a[index1--]-'0' : 0; 
            int num2 = (index2 >= 0) ? b[index2--]-'0' : 0;
            sum += num1 + num2;
            ans.push_back(sum%2+'0'); 
            sum /= 2;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
