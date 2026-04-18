class BSTIterator {
    std::stack<TreeNode*> _nodeStack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;

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
