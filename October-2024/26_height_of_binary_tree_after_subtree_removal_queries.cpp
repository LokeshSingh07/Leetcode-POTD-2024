// 2458. Height of Binary Tree After Subtree Removal Queries

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
    int level[100001];
    int height[100001];
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];

    int findHeight(TreeNode* root, int L){
        if(!root) return 0;

        // pre-compute
        level[root->val] = L;
        height[root->val] = max(findHeight(root->left, L+1), findHeight(root->right, L+1)) + 1;

        if(levelMaxHt[L] < height[root->val]){
            levelSecondMaxHt[L] = levelMaxHt[L];
            levelMaxHt[L] = height[root->val];
        }
        else if(levelSecondMaxHt[L] < height[root->val]){
            levelSecondMaxHt[L] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root, 0);

        vector<int> ans;
        for(auto q: queries){
            int L = level[q];
            int H = (height[q] == levelMaxHt[L]) ? levelSecondMaxHt[L] : levelMaxHt[L]; 
            int temp = L + H - 1;

            ans.push_back(temp);
        }

        return ans;
    }
};