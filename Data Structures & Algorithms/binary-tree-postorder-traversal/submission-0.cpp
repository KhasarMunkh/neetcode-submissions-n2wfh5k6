class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode* > nodeStack;
        stack<bool> visitedStack;

        TreeNode* curr = root;
        bool visited = false;
        
        nodeStack.push(curr);
        visitedStack.push(false);

        while (!nodeStack.empty()) {
            curr = nodeStack.top();
            nodeStack.pop();
            visited = visitedStack.top();
            visitedStack.pop();
            if (curr) {
                if (visited) {
                    result.push_back(curr->val);
                } else {
                    nodeStack.push(curr);
                    visitedStack.push(true);
                    nodeStack.push(curr->right);
                    visitedStack.push(false);
                    nodeStack.push(curr->left);
                    visitedStack.push(false);
                }
            }
        }
        
        return result;
    }
};