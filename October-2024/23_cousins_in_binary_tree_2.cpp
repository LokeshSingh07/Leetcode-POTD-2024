// 2641. Cousins in Binary Tree II

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
    void levelOrder(TreeNode* root, vector<int> &levelSum){
        queue<TreeNode*> q;

        // step1: Initial state
        q.push(root);
        q.push(NULL);
        long sum=0;

        // step2: BFS Logic
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode){
                sum += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            else{
                levelSum.push_back(sum);
                if(!q.empty()) q.push(NULL);
                sum = 0;
            }   
        }

    }

    void updateBT(TreeNode* root, vector<int> &levelSum){
        queue<TreeNode*> q;
        
        // Initial state
        q.push(root);
        root->val = 0;
        int i=1;

        // BFS
        while(!q.empty()){
            int n = q.size();

            while(n--){
                TreeNode* frontNode = q.front();
                q.pop();

                int siblingSum = 0;
                if(frontNode->left) siblingSum += frontNode->left->val;
                if(frontNode->right) siblingSum += frontNode->right->val;
                    

                if(frontNode->left){
                    frontNode->left->val = levelSum[i] - siblingSum;
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    frontNode->right->val = levelSum[i] - siblingSum;
                    q.push(frontNode->right);
                }
            }
            i++;
        }
        
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;

        // find each lelvel sum
        vector<int> levelSum;
        levelOrder(root, levelSum);

        // update each node value with cousion sum
        updateBT(root, levelSum);

        return root;
    }
};




// --------- SOLUTION IN ONE PASS  ---------

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*> q;
        
        // Initial state
        q.push(root);
        int levelSum = root->val;

        // BFS
        while(!q.empty()){
            int n = q.size();
            int nextLevelSum = 0;

            while(n--){
                TreeNode* frontNode = q.front();
                q.pop();

                // update the node
                frontNode->val = levelSum - frontNode->val;

                // calculate the sibling sum of the next level
                int siblingSum = 0;
                if(frontNode->left) siblingSum += frontNode->left->val;
                if(frontNode->right) siblingSum += frontNode->right->val;
                    

                if(frontNode->left){
                    nextLevelSum += frontNode->left->val;
                    frontNode->left->val = siblingSum;
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    nextLevelSum += frontNode->right->val;
                    frontNode->right->val = siblingSum;
                    q.push(frontNode->right);
                }
            }
            levelSum = nextLevelSum;
            nextLevelSum = 0;
        }
        

        return root;
    }
};