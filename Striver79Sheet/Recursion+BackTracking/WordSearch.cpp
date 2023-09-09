class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int row, int col, int index, int m, int n) {

        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '!') {
            return false;
        }

        char c = board[row][col];
        board[row][col] = '!';

        bool top = solve(board, word, row - 1, col, index+1, m, n);
        bool right = solve(board, word, row, col + 1, index+1, m, n);
        bool bottom = solve(board, word, row + 1, col, index+1, m, n);
        bool left = solve(board, word, row, col - 1, index+1, m, n);

        board[row][col] = c;

        return top || right || bottom || left;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        int index = 0;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (solve(board, word, i, j, index, m, n)) {
                    return true;
                }
            }
        }

        return false;
    }
};
