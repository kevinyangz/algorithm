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
    /*
        input parameters
        @root: 
        @count: longest consecutive sequence along the path 
        @lastVal: Root value from preivous layer
        outPut Parameters:
        @result: max Value of leftSubtree result and rightSubTree result
                 and current Layer result( result dervied from last layer)
    */
    int dfs(TreeNode* root, int count, int lastVal)
    {
        if(root==NULL)
        {
            return count;
        }
        if(root->val == lastVal+1)
        {
            count+=1;
        }
        else
        {
            count = 1;
        }
        int left = dfs(root->left,count,root->val);
        int right = dfs(root->right,count,root->val);
        
        return max(max(left,right),count);
    }
    int longestConsecutive(TreeNode* root) {
        if(root== NULL) return 0;
        
        return dfs(root,0,root->val-1);
        
    }
};
