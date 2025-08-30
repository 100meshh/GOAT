class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top=0,left=0,right=n-1,bottom=n-1;
        int initial=1;
        int final=n*n;
        while(top<=bottom && left<=right && initial<=final)
        {
            for(int i=left;i<=right;i++)
            {
                matrix[top][i]=initial;
                initial++;
            }
            top++;

            for(int j=top;j<=bottom;j++)
            {
                matrix[j][right]=initial;
                initial++;
            }
            right--;

        if(top<=bottom)
        {
            for(int j=right;j>=left;j--)
            {
                matrix[bottom][j]=initial;
                initial++;
            }
            bottom--;
        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--){
                matrix[i][left]=initial;
                initial++;
            }
            left++;
        }
        }
        return matrix;
    }
};