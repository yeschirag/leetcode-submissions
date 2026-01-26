class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &ans, int color, int inicolor){
        ans[sr][sc] = color;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        int n = image.size();
        int m = image[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int newrow = sr + delrow[i];
            int newcol = sc + delcol[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && image[newrow][newcol] == inicolor && ans[newrow][newcol] != color ){
                dfs(newrow, newcol, image, ans, color, inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,image,ans,color, iniColor);
        return ans;
    }
};