class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        /*int ans=left;
        for(int i=left+1;i<=right;i++)
        {
            ans=(ans)&(i);
            if(ans==0)
            return 0;
        }
        return ans;*/
        int count=0;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            count++;
        }
        int ans=left<<count;
        return ans;
        
    }
};