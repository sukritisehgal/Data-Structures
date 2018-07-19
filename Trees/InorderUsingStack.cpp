#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*>* st= new stack<TreeNode*>();
        std::vector<int> traversal;
        TreeNode* current = root;
        int flag=0;
        
        while(flag==0)
        {
            if(current!=nullptr)
            {
                st->push(current);
                current = current->left;
            }
            else
            {
                if(!st->empty())
                {
                    current = st->top();
                    traversal.push_back(current->val);
                    st->pop();
                    current=current->right;
                }
                else
                {
                    flag=1;
                }
            }
        }
       return traversal; 
    }
};