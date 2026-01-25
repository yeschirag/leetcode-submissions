/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root){
        int depth = 0;
        if(root == NULL) return 0;
        depth = 1 + max(getDepth(root->left), getDepth(root->right));
        return depth;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return getDepth(root);
    }
};