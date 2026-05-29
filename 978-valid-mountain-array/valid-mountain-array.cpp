class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        int max=0;
        int index=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                index=i;
            }
        }
        if(index==0)
        return false;
        if(index==arr.size()-1)
        return false;
        for(int i=index;i>0;i--)
        {
            if(arr[i-1]>=arr[i])
            return false;
        }
        for(int i=index+1;i<arr.size();i++)
        {
            if(arr[i]>=arr[i-1])
            return false;
        }
        return true;

    }
};