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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        while(!bfsq.empty()) {
            int n = bfsq.size();
            vector<int> res;
            while(n--) {
                auto temp = bfsq.front();
                bfsq.pop();
                res.push_back(temp->val);
                if(temp->left) bfsq.push(temp->left);
                if(temp->right) bfsq.push(temp->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
