// 2583. Kth Largest Sum in a Binary Tree

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;

        // step1: initial state
        q.push(root);
        q.push(NULL);

        // step2: BFS
        long long levelSum = 0;
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL){
                pq.push(levelSum);
                if(!q.empty()) q.push(NULL);
                levelSum = 0;
            }
            else{
                levelSum += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
        }

        while(pq.size() > k){
            pq.pop();
        }

        return pq.size() == k ? pq.top() : -1;
    }
};