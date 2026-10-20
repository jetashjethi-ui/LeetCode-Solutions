class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int string_idx) {
        // Base case: If we have matched the entire word
        if (string_idx == word.size()) {
            return true;
        }
        
        // Boundary check and character match check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[string_idx]) {
            return false;
        }
        
        // Temporarily mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore all 4 directions: Down, Up, Right, Left
        bool found = dfs(i + 1, j, board, word, string_idx + 1) ||
                     dfs(i - 1, j, board, word, string_idx + 1) ||
                     dfs(i, j + 1, board, word, string_idx + 1) ||
                     dfs(i, j - 1, board, word, string_idx + 1);
        
        // Backtrack: restore the cell's original character
        board[i][j] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Loop through the grid to find starting points
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};