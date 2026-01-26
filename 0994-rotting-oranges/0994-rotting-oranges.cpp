class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, m = grid.size(), n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m , vector<int> (n));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int delr[] = {0,1,0,-1};
        int delc[] = {1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front().first;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int row = r + delr[i];
                int col = c + delc[i];
                if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1 && visited[row][col] == 0){
                    q.push({{row,col}, t+1});
                    visited[row][col] = 2;
                }
            }
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        return time;

    }
};