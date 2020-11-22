
    //BFS Solution 
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty())
        {
            TreeNode* current = bfs.front();
            bfs.pop();
            //swap the left and right chield 
            TreeNode*temp = current->left;
            current->left = current->right;
            current->right = temp;
            if(current->right)
            {
                bfs.push(current->right);
            }
            if(current->left)
            {
                bfs.push(current->left);
            }
        }
        return root;
        

    }
