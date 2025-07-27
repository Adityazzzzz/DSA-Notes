#include<iostream>
using namespace std;

class Solution {
    int n, m;
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int ind) {
        if (ind >= word.size()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m)return false;
        
        if (board[i][j] != word[ind]) return false;
        char c = board[i][j];
        
        board[i][j] = '*'; //temp replace char

        bool check = dfs(board, i + 1, j, word, ind + 1) || dfs(board, i, j + 1, word, ind + 1) || dfs(board, i - 1, j, word, ind + 1) || dfs(board, i, j - 1, word, ind + 1);

        board[i][j] = c;
        return check;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};