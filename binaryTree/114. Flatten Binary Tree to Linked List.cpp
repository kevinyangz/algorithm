    TreeNode* helper(TreeNode* root)
    {
        if(root==NULL) return root;
        if(root->left==NULL && root->right==NULL ) return root;
        
        //rightRightMost should be the right Most node from its left subTree
        TreeNode* rightRightMost = NULL;
        TreeNode* leftRightMost = NULL;
        leftRightMost = helper(root->left);
        rightRightMost = helper(root->right);
       
        //we have left sub tree
        if(root->left)
        {
              leftRightMost->right = root->right;
              root->right = root->left;
        }
           
        //avoid infinite loop
        root->left= NULL;
        
        if(rightRightMost)
            return rightRightMost;
        return leftRightMost;
        
        
    }
    void flatten(TreeNode* root) {
        //thinking this problem from the smallest sub tree 
        //need the right most node if it has 
        helper(root);
    }
