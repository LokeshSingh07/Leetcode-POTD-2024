// 2415. Reverse Odd Levels of Binary Tree

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
    void dfs(TreeNode* left, TreeNode* right, int level){
        if(!left || !right) return;

        if((level&1) == 0){  // catch
            swap(left->val, right->val);
        }

        dfs(left->left, right->right, level+1);
        dfs(left->right, right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        dfs(root->left, root->right, level);
        return root;
    }
};