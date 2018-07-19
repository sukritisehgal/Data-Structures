int height(struct Node* node)
{
   // Your code here
   if(node==NULL)
   {
       return 0;
   }
   else
   {
       int ld=height(node->left);
       int rd=height(node->right);
       
       if(ld>rd)
        return ld+1;
    else
        return rd+1;
        
   }
}