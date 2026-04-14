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
    void inorder(TreeNode* root,vector<int>&vec)
    {
        if(root==NULL)
        return;
        if(root->left!=NULL)
        inorder(root->left,vec);
        vec.push_back(root->val);
        if(root->right!=NULL)
        inorder(root->right,vec);
        return;
    }
    bool isValidBST(TreeNode* root)
    {
        /*if(root->left!=NULL&&root->right!=NULL)
        {
            if((root->left->val)>=(root->val)||(root->right->val)<=(root->val))
            return false;
        }
        if(root->left!=NULL&&root->right==NULL)
        {
            if((root->left->val)>=(root->val))
            return false;
        }
        if(root->left==NULL&&root->right!=NULL)
        {
            if((root->right->val)<=(root->val))
            return false;
        }
        if(root->left!=NULL)
        isValidBST(root->left);
        if(root->right!=NULL)
        isValidBST(root->right);
        //if(root->right==NULL&&root->left==NULL)
        return true;*/
        vector<int>vec;
        inorder(root,vec);
        for(int i=0;i<vec.size()-1;i++)
        {
            if(vec[i]>=vec[i+1])
            return false;
        }
        return true;

    }
};