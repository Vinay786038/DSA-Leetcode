class Solution {
    struct Node
    {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;
    };
    vector<Node>tree;
    string str;
    Node merge(Node a,Node b)
    {
        Node res;
        res.len=a.len+b.len;
        res.leftChar=a.leftChar;
        res.rightChar=b.rightChar;
        res.pref=a.pref;
        if(a.pref==a.len&&a.rightChar==b.leftChar)
        {
            res.pref=a.len+b.pref;
        }
        res.suff=b.suff;
        if(b.suff==b.len&&a.rightChar==b.leftChar)
        {
            res.suff=b.len+a.suff;
        }
        res.best=max(a.best,b.best);
        if(a.rightChar==b.leftChar)
        {
            res.best=max(res.best,a.suff+b.pref);
        }
        return res;
    }
    void build(int node,int l,int r)
    {
        if(l==r)
        {
            tree[node]={1,1,1,1,str[l],str[l]};
            return;
        }
        int mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        tree[node]=merge(tree[node*2],tree[node*2+1]);
    }
    void update(int node,int l,int r,int idx,char ch)
    {
        if(l==r)
        {
            str[idx]=ch;
            tree[node]={1,1,1,1,ch,ch};
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
        {
            update(node*2,l,mid,idx,ch);
        }
        else
        {
            update(node*2+1,mid+1,r,idx,ch);
        }
        tree[node]=merge(tree[node*2],tree[node*2+1]);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices)
    {
        str=s;
        int n=s.size();
        tree.resize(4*n);
        build(1,0,n-1);
        vector<int>ans;
        for(int i=0;i<queryCharacters.size();i++)
        {
            update(1,0,n-1,queryIndices[i],queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
        
    }
};