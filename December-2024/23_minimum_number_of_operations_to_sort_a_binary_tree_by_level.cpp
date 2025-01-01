// 2471. Minimum Number of Operations to Sort a Binary Tree by Level

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
    int sortWithMinSwaps(vector<int> vec){
        int n = vec.size();
        int swaps = 0;
        vector<int> sortedVec(begin(vec), end(vec));
        sort(begin(sortedVec), end(sortedVec));

        // create map
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[vec[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(sortedVec[i] == vec[i]) continue;

            int idx = mp[sortedVec[i]];
            mp[vec[i]] = idx;
            mp[vec[idx]] = i;
            swap(vec[i], vec[idx]);

            swaps++;
        }

        return swaps;
    }


    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int res = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;

            while(n--){
                TreeNode* front = q.front();
                q.pop();
                vec.push_back(front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            res += sortWithMinSwaps(vec);
        }

        return res;
    }
};