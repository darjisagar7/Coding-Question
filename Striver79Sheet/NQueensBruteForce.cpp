#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
    bool isSafe(int row, int col, vector<string> board, int n) {

        int dupRow = row;
        int dupCol = col;

        while (row >=0 && col >=0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        row = dupRow;
        col = dupCol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

public:
    void solve(int col, vector<vector<string> > & ans, vector<string>& board, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row=0;row<n;row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
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
        solve(0, ans, board, n);
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Please enter the value n"<<endl;
    cin>>n;
    cout<<n;
    Solution obj;

    vector<vector<string> > ans = obj.solveNQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
