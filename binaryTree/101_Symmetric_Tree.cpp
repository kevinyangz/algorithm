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
class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right)
    {
        if(left==NULL && right==NULL) 
            return true;
        if(left==NULL || right==NULL)
            return false;
        
        return (left->val==right->val) && helper(left->right,right->left) && helper(left->left,right->right);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*>mystack;
        mystack.push(root->left);
        mystack.push(root->right);
        while(mystack.size()>1)
        {
            TreeNode* left = mystack.top();
            mystack.pop();
            TreeNode* right = mystack.top();
            mystack.pop();
            if(left==NULL && right==NULL) continue;
            if(left==NULL || right==NULL) return false;
            if(left->val != right->val) return false;
            mystack.push(left->right);
            mystack.push(right->left);
            mystack.push(left->left);
            mystack.push(right->right);
            
        }
        
        return (mystack.size()==0);
        //return helper(root->left,root->right);
    }
};
