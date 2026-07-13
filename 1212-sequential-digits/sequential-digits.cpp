class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int>vec;
        /*
        int m=low;
        int dig=high;
        while(m>9&&dig>9)
        {
            dig/=10;
            m/=10;
        }
        int p=m;
        while(true)
        {
            int sum=p;
            int x=p+1;
            bool f=true;
            while(sum<high)
            {
                sum=sum*10+x;
                if(sum>=low&&sum<=high)
                vec.push_back(sum);
                x++;
                if(x>9)
                {
                    break;
                }
                
            }
            p++;
            if(p>=dig)
            break;
            if(f==false)
            break;
        }*/
        string s="123456789";
        for(int len=2;len<=9;len++)
        {
            for(int i=0;i+len<=9;i++)
            {
                int num=stoi(s.substr(i,len));
                if(num>=low&&num<=high)
                vec.push_back(num);
            }
        }
        //sort(vec.begin(),vec.end());
        return vec;
        
    }
};