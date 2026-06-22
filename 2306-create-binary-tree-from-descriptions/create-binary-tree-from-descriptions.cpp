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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        map<int,int>mp1;
        int n=descriptions.size();
        for(int i=0;i<n;i++)
        {
            mp1[descriptions[i][1]]=1;
        }
        map<int,TreeNode*>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[descriptions[i][0]])
            {
                if(mp[descriptions[i][1]]&&descriptions[i][2]==0)
                {
                    mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
                }
                else if(mp[descriptions[i][1]]&&descriptions[i][2]==1)
                {
                    mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
                }
                else
                {
                    if(descriptions[i][2]==0)
                    {
                        mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
                        mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
                    }
                    else
                    {
                        mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
                        mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
                    }
                }
            }
            else
            {
                mp[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
                if(mp[descriptions[i][1]]&&descriptions[i][2]==0)
                {
                    mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
                }
                else if(mp[descriptions[i][1]]&&descriptions[i][2]==1)
                {
                    mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
                }
                else
                {
                    if(descriptions[i][2]==0)
                    {
                        mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
                        mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
                    }
                    else
                    {
                        mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
                        mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
                    }
                }

            }
            
        }
        for(auto x:mp)
        {
            if(mp1[x.first])
            {
                continue;
            }
            else
            return x.second;

        }
        return NULL;
        
    }
};