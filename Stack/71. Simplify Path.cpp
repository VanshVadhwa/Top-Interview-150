class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> st;
        string dir = "";

        for(int i=0;i<n;i++) {
            if(path[i]=='/') {
                if(!dir.empty()) {
                    if(dir=="..") {
                        if(!st.empty()) st.pop_back();
                    }
                    else if(dir != ".") {
                        st.push_back(dir);
                    }
                    dir = "";
                }
            }
            else {
                dir += path[i];
            }
        }

        if(!dir.empty()) {
            if(dir=="..") {
                if(!st.empty()) st.pop_back();
            }
            else if(dir != ".")
                st.push_back(dir);
        }

        string ans = "/";
        for(int i=0;i<st.size();i++) {
            ans += st[i];
            if(i != st.size()-1) ans += '/';
        }

        return ans;
    }
};
