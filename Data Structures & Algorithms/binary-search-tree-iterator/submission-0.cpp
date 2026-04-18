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
class BSTIterator {
    std::stack<TreeNode*> _nodeStack;
public:
    // we want our curr pointer to always be pointing 
    BSTIterator(TreeNode* root) {
        _nodeStack.push(root);

        TreeNode* curr = root->left;

        while (curr) {
            _nodeStack.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        int result;
        if (!_nodeStack.empty()) {
            TreeNode* curr = _nodeStack.top();
            _nodeStack.pop();
            result = curr->val;
            if (curr->right) {
                curr = curr->right;
                _nodeStack.push(curr);
                curr = curr->left;
                while (curr) {
                    _nodeStack.push(curr);
                    curr = curr->left;
                }
            }
        }
        return result;
    }
    
    bool hasNext() {
        if (!_nodeStack.empty()) {
            return true;
        }
        return false;
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */