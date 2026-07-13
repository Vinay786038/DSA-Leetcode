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

    TreeNode* build(vector<int>& pre, int ps, int pe,
                    vector<int>& post, int qs, int qe,
                    unordered_map<int,int>& mp)
    {
        if(ps > pe) return NULL;

        TreeNode* root = new TreeNode(pre[ps]);

        if(ps == pe) return root;

        int leftRoot = pre[ps + 1];

        int idx = mp[leftRoot];

        int leftSize = idx - qs + 1;

        root->left = build(pre,
                           ps + 1,
                           ps + leftSize,
                           post,
                           qs,
                           idx,
                           mp);

        root->right = build(pre,
                            ps + leftSize + 1,
                            pe,
                            post,
                            idx + 1,
                            qe - 1,
                            mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder)
    {
        unordered_map<int,int> mp;

        for(int i=0;i<postorder.size();i++)
            mp[postorder[i]] = i;

        return build(preorder,
                     0,
                     preorder.size()-1,
                     postorder,
                     0,
                     postorder.size()-1,
                     mp);
    }
};