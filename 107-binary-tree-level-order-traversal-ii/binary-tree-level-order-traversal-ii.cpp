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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int> >ans;
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
                TreeNode* temp=q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
                size--;
            }
            ans.push_back(vec);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};