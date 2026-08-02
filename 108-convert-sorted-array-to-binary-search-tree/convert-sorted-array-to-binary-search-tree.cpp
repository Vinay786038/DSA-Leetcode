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
    TreeNode* BST(TreeNode* root,int left,int right,vector<int>&nums)
    {
        if(left>right)
        {
            return NULL;
        }
        int mid=left+(right-left)/2;
        if(root==NULL)
        {
            root=new TreeNode(nums[mid]);
        }
        root->left=BST(root->left,left,mid-1,nums);
        root->right=BST(root->right,mid+1,right,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        TreeNode *root=NULL;
        int n=nums.size();
        root=BST(root,0,n-1,nums);
        return root;
    }
};