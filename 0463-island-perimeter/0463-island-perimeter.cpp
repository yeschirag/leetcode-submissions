class Solution {
public:
    void dfs(int ini_row, int ini_col, vector<vector<int>>& grid, int &perimeter,vector<vector<int>>& visited){
        visited[ini_row][ini_col] = 1;
        int row_grid = grid.size(),col_grid = grid[0].size();
        int del_row[] = {0,1,0,-1};
        int del_col[] = {1,0,-1,0};
        int row = ini_row;
        int col = ini_col;
        for(int i = 0 ; i < 4 ; i++ ){
            row = ini_row + del_row[i];
            col = ini_col + del_col[i];
            if((row >= 0 && row < row_grid && col >= 0 && col < col_grid && grid[row][col] == 0) || (row < 0 || row >= row_grid || col < 0 || col >= col_grid)){
                perimeter++;
            }
            else if(row >= 0 && row < row_grid && col >= 0 && col < col_grid && grid[row][col] == 1 && visited[row][col] != 1){
                dfs(row, col, grid, perimeter,visited);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int ini_row = 0 , ini_col = 0;
        int row = grid.size(),col = grid[0].size();
        for(int i = 0; i < row; i++){
            int flag = 0;
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j]==1){
                    ini_row = i;
                    ini_col = j;
                    flag = 1;
                    break;
                }
                if(flag == 1) break;
            }
        }
        vector<vector<int>> visited(row, vector<int> (col) );
        dfs(ini_row,ini_col,grid,perimeter,visited);
        return perimeter;
    }
};