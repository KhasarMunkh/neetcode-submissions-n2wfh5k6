class BSTIterator {
    std::stack<TreeNode*> _nodeStack;
    void push_left_children(TreeNode* node) {
        while (node) {
            _nodeStack.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_left_children(root);
    }
    
    int next() {
        int result;
        if (!_nodeStack.empty()) {
            TreeNode* curr = _nodeStack.top();
            _nodeStack.pop();
            result = curr->val;
            curr = curr->right;
            if (curr) {
                _nodeStack.push(curr);
                push_left_children(curr->left);
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
