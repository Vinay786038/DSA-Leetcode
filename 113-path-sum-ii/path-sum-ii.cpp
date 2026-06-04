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
    void dfs(TreeNode* root,int target,vector<int>&vec,vector<vector<int>>&ans)
    {
        if(root==NULL)
        return;
        vec.push_back(root->val);
        target-=root->val;

        if(root->left==NULL&&root->right==NULL&&target==0)
        ans.push_back(vec);
        dfs(root->left,target,vec,ans);
        dfs(root->right,target,vec,ans);
        vec.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        vector<int>vec;
        dfs(root,targetSum,vec,ans);
        return ans;
    }
};