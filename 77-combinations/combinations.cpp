class Solution {
public:
    void combi(vector<vector<int>>&ans,vector<int>&temp,int n,int k){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(n==0)return;
        //notpick
        combi(ans,temp,n-1,k);
        //pick
        temp.push_back(n);
        combi(ans,temp,n-1,k-1);
        temp.pop_back();

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        combi(ans,temp,n,k);
        return ans;
    }
};