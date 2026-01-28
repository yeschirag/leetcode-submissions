class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else mat[i][j] = -1;
            }
        }
        int delr[] = {0,1,0,-1};
        int delc[] = {1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int row = r + delr[i];
                int col = c + delc[i];
                if(row < m && row >= 0 && col >= 0 && col < n && mat[row][col] == -1){
                    mat[row][col] = 1 + mat[r][c];
                    q.push({row,col});
                }
            }
        }
        return mat;

    }
};