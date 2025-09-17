class Solution {
public:
    string sortSentence(string s) {
        int count = 0;
        int index = 0;
        vector<string> ans(10);
        string temp;
        while (index < s.size()) {
            if (s[index] == ' ') {
                int position = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[position - 1] = temp;
                temp.clear();
                count++;
            } else {
                temp += s[index];
            }
            index++;
        }
        int position = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[position - 1] = temp;
        temp.clear();
        count++;
        for (int i = 0; i < count; i++) {
            temp += ans[i];
            temp += ' ';
        }
        temp.pop_back();
        return temp;
    }
};