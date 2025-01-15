class Solution {
private:
    int wordsLength(vector<string>& words) {
        int ans = 0;
        for (string s : words) {
            ans += s.length();
        }
        return ans;
    }

    void countWords(string s, vector<string>& words) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                string temp = "";
                while (i < s.length() && s[i] != ' ') {
                    temp += s[i];
                    i++;
                }
                words.push_back(temp);
            }
        }
    }

    vector<string> ansArray(vector<string>& arr, int maxLength) {
        vector<string> ans;

        for (int i = 0; i < arr.size(); i++) {
            vector<string> words;
            countWords(arr[i], words); 
            int n = words.size();

            if (n == 1) {
                string temp = words[0];
                temp += string(maxLength - temp.length(), ' ');
                ans.push_back(temp);
                continue;
            }

            int wordLen = wordsLength(words);
            int totalSpaces = maxLength - wordLen;
            int spaceBetween = totalSpaces / (n - 1);
            int extraSpaces = totalSpaces % (n - 1);

            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += words[j]; 
                if (j < n - 1) {  
                    temp += string(spaceBetween, ' ');
                    if (extraSpaces > 0) {
                        temp += ' ';
                        extraSpaces--;
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        vector<string> tempLine;
        int currLen = 0;

        for (int i = 0; i < n; i++) {
            int wordLen = words[i].length();

            if (currLen + wordLen + tempLine.size() > maxWidth) {
                string temp = "";

                int totalSpaces = maxWidth - currLen;
                int spaceBetween = tempLine.size() > 1 ? totalSpaces / (tempLine.size() - 1) : totalSpaces;
                int extraSpaces = tempLine.size() > 1 ? totalSpaces % (tempLine.size() - 1) : 0;

                for (int j = 0; j < tempLine.size(); j++) {
                    temp += tempLine[j];
                    if (j < tempLine.size() - 1) {
                        temp += string(spaceBetween, ' ');
                        if (extraSpaces > 0) {
                            temp += ' ';
                            extraSpaces--;
                        }
                    }
                }
                temp += string(maxWidth - temp.length(), ' '); 
                ans.push_back(temp);
                tempLine.clear();
                currLen = 0;
            }

            tempLine.push_back(words[i]);
            currLen += wordLen;
        }

        string lastLine = "";
        for (int i = 0; i < tempLine.size(); i++) {
            lastLine += tempLine[i];
            if (i < tempLine.size() - 1) {
                lastLine += ' ';
            }
        }
        
        lastLine += string(maxWidth - lastLine.length(), ' ');
        ans.push_back(lastLine);

        return ans;
    }
};
