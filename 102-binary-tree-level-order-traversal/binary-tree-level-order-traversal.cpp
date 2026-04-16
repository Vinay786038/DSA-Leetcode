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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        if(root==NULL)
        return ans;
        q.push(root);
        while(q.empty()!=1)
        {
            vector<int>vec;
            int size=q.size();
            while(size>0)
            {
                TreeNode* temp1=q.front();
                q.pop();
                vec.push_back(temp1->val);
                size--;
                
                if(temp1->left!=NULL)
                q.push(temp1->left);
                if(temp1->right!=NULL)
                q.push(temp1->right);
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};