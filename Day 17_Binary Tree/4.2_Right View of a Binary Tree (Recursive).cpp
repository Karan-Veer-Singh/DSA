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
    
    void rightView(TreeNode *root, int level, int &maxLevel, vector<int> &ans)
    {
        if(root == NULL)
            return;
        
        if(level > maxLevel)
        {
            maxLevel = level;
            ans.push_back(root -> val);
        }
        
        rightView(root -> right, level+1, maxLevel, ans);
        rightView(root -> left, level+1, maxLevel, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxlevel = -1;
        rightView(root, 0, maxlevel, ans);
        
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-right-side-view/
