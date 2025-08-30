class Solution {
public:
    int m, n;
    int row[8] = {-1,-1,-1,0,0,1,1,1};
    int col[8] = {-1,0,1,-1,1,-1,0,1};

    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> matrix = board; // copy original

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;

                // count 8 neighbors
                for (int k = 0; k < 8; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (valid(ni, nj) && matrix[ni][nj] == 1) {
                        live++;
                    }
                }

                // Apply rules
                if (matrix[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 0; // dies
                    } else {
                        board[i][j] = 1; // survives
                    }
                } else { //matrix[i][j] == 0
                    if (live == 3) {
                        board[i][j] = 1; // reproduction
                    }
                }
            }
        }
    }
};
