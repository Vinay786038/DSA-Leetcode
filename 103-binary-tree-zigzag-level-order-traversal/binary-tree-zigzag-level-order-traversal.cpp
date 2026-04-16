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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        int a=0;
        while(q.empty()!=1)
        {
            int size=q.size();
            vector<int>vec(size);
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                int index = (a == 0) ? i : size - 1 - i;
                vec[index] = temp->val;
                // ALWAYS normal order
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            a = 1 - a;  // flip direction
            ans.push_back(vec);
        }
        return ans;
        
    }
};