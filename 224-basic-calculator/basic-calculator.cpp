class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num=0,res=0,sign=1;

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isdigit(c)) num=num*10+(c-'0');

            else if(c=='+'){
                res+=num*sign;
                num=0;
                sign=1;
            }
            else if(c=='-'){
                res+=num*sign;
                num=0;
                sign=-1;
            }
            else if(c=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(c==')'){
                res+=num*sign;
                num=0;
                int prev_sign=st.top();st.pop();
                int prev_res=st.top();st.pop();
                res=prev_res+prev_sign*res;
            }
        }
        res+=num*sign;
        return res;
    }
};