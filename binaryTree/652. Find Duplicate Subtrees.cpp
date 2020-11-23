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
    unordered_map<string,int>cache;
    vector<TreeNode*>result;
    string helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return "#";
        }
        
        
        string left = helper(root->left);
        string right = helper(root->right);
        //only post order traversal can give you the seralization of tree based on root
        string current = left+","+right+","+to_string(root->val);
        
        if(cache.count(current) > 0 && cache[current]==1)
        {
                result.push_back(root);
        }
        cache[current]++;
        
        
        return current;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //how do I know the structure of a tree of the current root
     helper(root);
        return result;
    }
};
