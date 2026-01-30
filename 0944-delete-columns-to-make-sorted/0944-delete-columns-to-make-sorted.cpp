class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int mindel = 0, m = strs.size(), n = strs[0].size();
        //cout << m << n ;
        for(int j = 0 ; j < n ; j++){
            for(int i = 0 ; i < m -1 ; i++){
                if(strs[i][j] > strs[i+1][j]){
                    mindel++;
                    break;
                }
            }
        }
        return mindel;
    }
};