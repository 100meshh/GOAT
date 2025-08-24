class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int operator2=st.top();
                st.pop();
                int operator1=st.top();
                st.pop();

                if(tokens[i]=="+")st.push(operator1+operator2);
                if(tokens[i]=="-")st.push(operator1-operator2);
                if(tokens[i]=="*")st.push(operator1*operator2);
                if(tokens[i]=="/")st.push(operator1/operator2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};