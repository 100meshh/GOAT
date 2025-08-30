class Solution {
public:
bool dfs(vector<vector<char>>& board, string word,int i,int j,int count){
    //basecase
    if(count==word.size())return true;
    //base case
    if(i<0||j<0||i>=board.size()||j>=board[0].size()||word[count]!=board[i][j]) return false;

    //make visited the found guy
    char temp=board[i][j];
    board[i][j]='$';
    //traverse all four sides
    bool found=dfs(board,word,i+1,j,count+1) || dfs(board,word,i-1,j,count+1) || dfs(board,word,i,j-1,count+1) || dfs(board,word,i,j+1,count+1);

    //backtrack
    board[i][j]=temp;
    return found;

}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};