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
    TreeNode* CBST(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            root=new TreeNode(val);
            return root;
        }
        if(val>root->val)
        {
            root->right=CBST(root->right,val);
        }
        if(val<root->val)
        {
            root->left=CBST(root->left,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n=preorder.size();
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<n;i++)
        {
            root=CBST(root,preorder[i]);
        }
        return root;

        
    }
};