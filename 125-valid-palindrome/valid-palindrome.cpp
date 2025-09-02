class Solution {
public:
                //recursion soln


    bool check(string &s,int start,int end){
        if(start>=end)return true;
        if(s[start]!=s[end])return false;
        return check(s,start+1,end-1);
    }
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
             if (isalnum(s[i]))  
            str+=tolower(s[i]);
        }
        int n=str.size();
        return check(str,0,n-1);
    }
};