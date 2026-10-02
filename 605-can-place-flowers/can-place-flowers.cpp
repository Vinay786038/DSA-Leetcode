class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int size=flowerbed.size();
        if(size<2)
        {
            if(flowerbed[0]==0)
            {
                n--;
                return true;
            }
        }
        if(n==0)
        return true;
        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                if(flowerbed[i]==0&&flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    i++;
                    n--;
                }
            }
            else if(i==size-1)
            {
                if(flowerbed[i]==0&&flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;
                    i++;
                    n--;
                }

            }
            else if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                i++;
                n--;
            }
            if(n==0)
            {
                return true;
            }
        }
        return false;
        
    }
};