class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
        int mini=1e8;
        for(int j=0;j<m;j++) prev[j]=matrix[0][j];
        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+prev[j];
                int upleft=matrix[i][j];
      if(j-1>=0) upleft+=prev[j-1];
                else upleft+=1e8;

                int upright=matrix[i][j];
      if(j+1<m) upright+=prev[j+1];
                else upright+=1e8;
                curr[j]=min(up,min(upleft,upright));
            }
            prev=curr;
        }
        // int mini=1e8;
        for(int j=0;j<m;j++){
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};