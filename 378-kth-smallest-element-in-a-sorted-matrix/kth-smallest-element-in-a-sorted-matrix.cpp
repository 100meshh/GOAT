class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         vector<pair<int,pair<int,int>>>temp;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(matrix[i][0],make_pair(i,0)));
        }
        priority_queue<
    pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> P(temp.begin(), temp.end());
        int ans;
        pair<int,pair<int,int>> Element;
        int i,j;
        while(k--){
            Element=P.top();
            P.pop();
            ans=Element.first;
            i=Element.second.first;
            j=Element.second.second;
            if(j+1<n)P.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
        }
        return ans;
    
    }
};