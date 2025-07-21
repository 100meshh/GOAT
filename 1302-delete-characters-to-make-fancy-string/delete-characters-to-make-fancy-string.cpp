class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string str;
        for(int i=0;i<s.size();i++){
            if(i==0) str+=s[i];
            else if(s[i]!=s[i-1]){
                str+=s[i];
                count=1;
            }
            else{
                if(s[i]==s[i-1] && count<2) {
                    str+=s[i];
                    count++;
                }
            }
        }
        return str;
    }
};