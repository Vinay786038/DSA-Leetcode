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
    vector<int> rightSideView(TreeNode* root) {
        queue<vector<TreeNode*>>q;
        vector<int>ans;
        if(root==NULL)
        return ans;
        q.push({root});
        while(!q.empty())
        {
            vector<TreeNode*>vec1=q.front();
            q.pop();
            ans.push_back(vec1[0]->val);
            int n=vec1.size();
            vector<TreeNode*>vec2;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=vec1[i];
                if(temp->right)
                {
                    vec2.push_back(temp->right);
                }
                if(temp->left)
                {
                    vec2.push_back(temp->left);
                }
            }
            if(!vec2.empty())
            q.push(vec2);
        }
        return ans;
        
    }
};