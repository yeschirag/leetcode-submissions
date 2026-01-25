class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;

        while(k > 0 && nums[k - 1] < nums[k]) {
            k--;
        }

        return k;
    }
};
