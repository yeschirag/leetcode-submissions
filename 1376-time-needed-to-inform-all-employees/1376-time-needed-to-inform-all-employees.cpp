class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> children(n);
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                children[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({headID, 0});

        int ans = 0;

        while(!q.empty()){
            auto [u, time] = q.front();
            q.pop();

            ans = max(ans, time);

            for(int v : children[u]){
                q.push({v, time + informTime[u]});
            }
        }

        return ans;
    }
};
