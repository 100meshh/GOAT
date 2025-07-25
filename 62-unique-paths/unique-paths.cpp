class Solution {
public:
    int uniquePaths(int m, int n) {
        //SPACE OPTIMIZED
    vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                int up=0,left=0;
                if(i==0 && j==0) temp[j]=1;
                else{
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[n-1];    
    }
};
