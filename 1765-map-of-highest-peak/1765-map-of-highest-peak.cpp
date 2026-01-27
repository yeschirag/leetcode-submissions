class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                }
                // else isWater[i][j] = 0;
            }
        }

        int delr[] = {0, 1, 0, -1}, delc[] = {1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = r + delr[i];
                int col = c + delc[i];
                if (row >= 0 && row < m && col >= 0 && col < n &&
                    isWater[row][col] == 0) {
                    isWater[row][col] = isWater[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                isWater[i][j]--;
            }
        }
        return isWater;
    }
};