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
    void paths(TreeNode* root,vector<string>&vec,string s)
    {
        if(root==NULL)
        {
            return;
        }
        if(s.size()==0)
        {
            s+=to_string(root->val);;
        }
        else
        {
            s+="->"+to_string(root->val);
        }
        if(root->left==NULL&&root->right==NULL)
        {
            vec.push_back(s);
            return;
        }
        
        paths(root->left,vec,s);
        paths(root->right,vec,s);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<string>vec;
        string s="";
        paths(root,vec,s);
        return vec;

        
    }
};