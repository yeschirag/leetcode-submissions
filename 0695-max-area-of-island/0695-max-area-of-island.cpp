class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, int m, int n) {
        grid[r][c] = 0;
        int delr[] = {0, 1, 0, -1}, delc[] = {1, 0, -1, 0}, area = 1;
        for (int i = 0; i < 4; i++) {
            int row = r + delr[i];
            int col = c + delc[i];
            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1){
                area = area + dfs(row,col,grid, m , n);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0, m = grid.size(), n = grid[0].size(), row = 0, col = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j  < n ; j++){
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                    maxarea = max(maxarea, dfs(row, col, grid, m, n));
                }
            }
        }
        return maxarea;
    }
};