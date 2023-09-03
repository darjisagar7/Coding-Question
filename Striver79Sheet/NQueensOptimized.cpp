class Solution {
public:
    void solve(int col, vector<vector<string> > & ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiagnol, vector<int>& lowerDiagnol, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row=0;row<n;row++) {
            if (leftRow[row] == 0 && upperDiagnol[n -1 + col - row] == 0 && lowerDiagnol[row + col] == 0) {
                leftRow[row] = 1;
                upperDiagnol[n - 1 + col - row] = 1;
                lowerDiagnol[row + col] = 1;
                board[row][col] = 'Q';
                solve(col + 1, ans, board, leftRow, upperDiagnol, lowerDiagnol, n);
                leftRow[row] = 0;
                upperDiagnol[n - 1 + col - row] = 0;
                lowerDiagnol[row + col] = 0;
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i=0;i<n;i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDiagnol(2*n-1, 0), lowerDiagnol(2*n-1, 0);
        solve(0, ans, board, leftRow, upperDiagnol, lowerDiagnol, n);
        return ans;
    }
};
