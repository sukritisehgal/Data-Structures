bool isSumTree(struct Node* root)
{
    if(root==NULL)
        return false;
        
    if(root->left==NULL && root->right==NULL)
        return true;
        
    if(root->data==root->left->data+root->right->data)
    {
        isSumTree(root->left);
        isSumTree(root->right);
        
        return true;
    }
    return false;
     // Your code here
}