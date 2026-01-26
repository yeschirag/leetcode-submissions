class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        vector<vector<int>> ans;
        int abs_diff = INT_MAX;
        for(int i = 0 ; i < len - 1; i++){
            abs_diff = min(abs_diff,abs(arr[i] - arr[i+1]));
        }
        for(int i = 0 ; i < len - 1 ; i++){
            if(abs(arr[i] - arr[i+1]) == abs_diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};