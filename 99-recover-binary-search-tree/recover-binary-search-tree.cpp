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
    vector<int>values;
    vector<TreeNode*>Node;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left);
        values.push_back(root->val);
        Node.push_back(root);
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        vector<int>sorted=values;
        sort(sorted.begin(),sorted.end());
        int first=-1;
        int second=-1;
        for(int i=0;i<sorted.size();i++)
        {
            if(values[i]!=sorted[i])
            {
                if(first==-1)
                {
                    first=i;
                }
                else
                {
                    second=i;
                }
            }
        }
        swap(Node[first]->val,Node[second]->val);
        return;

        
    }
};