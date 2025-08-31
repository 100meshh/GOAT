class Solution {
public:
int m,n;
int drow[4]={-1,1,0,0};
int dcol[4]={0,0,-1,1};
void dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==1) return;
        grid[r][c] = 1; 
        for(int k=0;k<4;k++){
            dfs(grid, r+drow[k], c+dcol[k]);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;

        for(int i=0;i<m;i++){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][n-1]==0) dfs(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==0) dfs(grid,0,j);
            if(grid[m-1][j]==0) dfs(grid,m-1,j);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};