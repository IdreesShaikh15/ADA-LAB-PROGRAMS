class Solution {
    private void dfs(int x, int y, char[][] board, boolean[][] vis) {
        int n = board.length;
        int m = board[0].length;
        vis[x][y] = true;

        int[] delx = {-1, 0, 1, 0};
        int[] dely = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newx = x + delx[i];
            int newy = y + dely[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
                !vis[newx][newy] && board[newx][newy] == 'O') {
                dfs(newx, newy, board, vis);
            }
        }
    }

    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        boolean[][] vis = new boolean[n][m];

        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, vis);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board, vis);
        }

        
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, vis);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board, vis);
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
}