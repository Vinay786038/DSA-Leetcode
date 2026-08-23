class Solution {
public:
    bool sumGame(string num)
    {
        int n=num.size();
        int leftsum=0;
        int rightsum=0;
        int Qleft=0;
        int Qright=0;
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?')
            {
                Qleft++;
            }
            else
            {
                leftsum+=num[i]-'0';
            }
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?')
            {
                Qright++;
            }
            else
            {
                rightsum+=num[i]-'0';
            }
        }
        int diff=leftsum-rightsum;
        int Qdiff=Qleft-Qright;
        if((Qdiff%2)!=0)
        {
            return true;
        }
        if(diff==(-9*(Qdiff/2)))
        {
            return false;
        }
        return true;  
    }
};