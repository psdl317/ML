#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<string> &board, int row, int col, int n) {
    // Check column above (0..row-1)
    for (int i = 0; i < n; ++i)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row , j = col ; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row , j = col ; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

void nQ(vector<string> &board, int row, int n, vector<vector<string>> &res) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            nQ(board, row + 1, n, res);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    nQ(board, 0, n, res);
    return res;
}

int main() {
    int n;
    cout << "Enter the value of N for N-Queens: ";
    if (!(cin >> n)) return 0;
    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto &solution : solutions) {
        for (const auto &row : solution){
            cout << row << '\n';
        } 
        cout << '\n';
    }
    return 0;
}
