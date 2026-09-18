class Solution {
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        int n=s.size();
        vector<int>first(26,n);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++)
        {
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }
        vector<pair<int,int>>intervals;
        for(int c=0;c<26;c++)
        {
            if(last[c]==-1)
            {
                continue;
            }
            int l=first[c];
            int r=last[c];
            bool x=true;
            for(int i=l;i<=r;i++)
            {
                int y=s[i]-'a';
                if(first[y]<l)
                {
                    x=false;
                    break;
                }
                r=max(r,last[y]);
            }
            if(x)
            {
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){return a.second<b.second;});
        vector<string>ans;
        int prevend=-1;
        for(auto &[l,r]:intervals)
        {
            if(l>prevend)
            {
                ans.push_back(s.substr(l,r-l+1));
                prevend=r;
            }
        }
        return ans;
        
    }
};