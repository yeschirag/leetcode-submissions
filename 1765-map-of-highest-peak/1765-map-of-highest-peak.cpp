class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[i][j] = -1;
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int delr[] = {0, 1, 0, -1}, delc[] = {1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = r + delr[i];
                int col = c + delc[i];
                if(row >= 0 && row < m && col>= 0 && col < n && isWater[row][col] == 0 && height[row][col] == -1 ){
                    height[row][col] = height[r][c] + 1;
                    q.push({row,col});
                }
            }
        }
        return height;
    }
};