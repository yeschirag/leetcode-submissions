class Solution {
public:
    void dfs(int r , int c, vector<vector<char>>& grid, int m , int n){
        grid[r][c] = '0';
        int delr[] = {0,1,0,-1};
        int delc[] = {1,0,-1,0};
        for(int i = 0 ; i < 4 ; i++){
            int row = r + delr[i];
            int col = c + delc[i];
            if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1'){
                dfs(row,col,grid,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size() , count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return count;
    }
};