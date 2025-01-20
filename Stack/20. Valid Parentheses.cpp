class Solution {
private:
    bool isClosing(char c) {
        return c==')' || c==']' || c=='}';
    }
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for(char c : s) {
            if(isClosing(c)) {
                if(st.empty()) return false;
                if(c==')' && st.top() != '(') return false;
                if (c!=')' && st.top()+2 != c) return false;
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        return st.empty();
    } 
};
