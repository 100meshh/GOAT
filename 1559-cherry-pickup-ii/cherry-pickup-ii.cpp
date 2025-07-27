class Solution {
public:
int f(int i,int j1,int j2,int rows,int cols,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    //base case
    // out of bound
    if(j1<0 || j2<0 || j1 >=cols || j2 >= cols) return -1e8;
    //out of destination
    if(i==rows-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+ grid[i][j2];
    }

    //check in dp
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    
    //explore all paths
    int maxi=-1e8;
    for(int dirj1=-1; dirj1<2 ; dirj1++){
        for(int dirj2=-1; dirj2<2 ; dirj2 ++){
            int value=0;
            if(j1==j2) value=grid[i][j1];
            else value=grid[i][j1]+grid[i][j2];
            value+=f(i+1,j1+dirj1,j2+dirj2,rows,cols,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]= maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>>dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return f(0,0,cols-1,rows,cols,grid,dp);
    }
};