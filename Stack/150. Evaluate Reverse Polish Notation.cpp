class Solution {
private:
    bool isNotNum(string s) {
        return (s=="+" || s=="-" || s=="*" || s=="/");
    }
    int total(string s, int num1, int num2) {
        if(s=="+") return num1 + num2;
        if(s=="-") return num1 - num2;
        if(s=="*") return num1 * num2;
        return num1 / num2;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s : tokens) {
            if(isNotNum(s)) {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                st.push(total(s,num2,num1));
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
