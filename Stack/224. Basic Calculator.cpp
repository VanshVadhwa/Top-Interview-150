class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int ans = 0, sign = 1;
        stack<int> st;

        for(int i=0;i<n;i++) {
            char c = s[i];

            if(isdigit(c)) {
                int num = 0;
                while(i<n && isdigit(s[i])) {
                    num = num*10 + (s[i++]-'0');
                }
                i--;
                ans += num*sign;
            }

            if(c=='+') {
                sign = 1;
            }
            if(c=='-') {
                sign = -1;
            }

            if(c=='(') {
                st.push(ans);
                st.push(sign);
                ans = 0, sign = 1;
            }

            if(c==')') {
                int prevSign = st.top(); st.pop();
                int prevAns = st.top(); st.pop();
                ans = prevAns + ans*prevSign;
            }
        }

        return ans;
    }
};
