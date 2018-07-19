std::vector<int> traversal;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root!=nullptr)
        {
            inorderTraversal(root->left);
            traversal.push_back(root->val);
            inorderTraversal(root->right);
        }
        return traversal;
    }
};