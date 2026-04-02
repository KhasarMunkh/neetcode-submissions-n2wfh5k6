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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversal(result, root);
        return result;
    }
    void preorderTraversal(vector<int>& result, TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }
        result.push_back(curr->val);
        preorderTraversal(result, curr->left);
        preorderTraversal(result, curr->right);
    }
};