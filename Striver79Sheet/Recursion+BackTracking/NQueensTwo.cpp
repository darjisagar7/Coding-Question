class Solution {
public:
    void solve(int col, int& ans, vector<string>& board, int n, vector<int>& leftRows, vector<int>& upperDiagnol, vector<int>& lowerDiagnol) {

        if (col == n) {
            ans += 1;
            return;
        }

        for (int row=0;row<n;row++) {
            if (leftRows[row] == 0 && upperDiagnol[col + row] == 0 && lowerDiagnol[n-1+col-row] == 0) {
                leftRows[row] = 1;
                upperDiagnol[col + row] = 1;
                lowerDiagnol[n-1+col-row] = 1;
                solve(col+1, ans, board, n, leftRows, upperDiagnol, lowerDiagnol);
                leftRows[row] = 0;
                upperDiagnol[col + row] = 0;
                lowerDiagnol[n-1+col-row] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board;
        string s(n, '.');
        vector<int> leftRows(n, 0);
        vector<int> upperDiagnol(2*n - 1, 0);
        vector<int> lowerDiagnol(2*n - 1, 0);

        for (int i=0;i<n;i++) {
            board.push_back(s);
        }

        solve(0, ans, board, n, leftRows, upperDiagnol, lowerDiagnol);
        return ans;
    }
};
