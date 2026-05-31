class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.size()-1;
        int j=b.size()-1;
        string s="";
        int carry=0;
        while(i>=0||j>=0||carry!=0)
        {
            int x=0;
            int y=0;
            if(i>=0&&j>=0)
            {
                x=a[i]-'0';
                y=b[j]-'0';
                i--;
                j--;
            }
            else if(i>=0&&j<0)
            {
                x=a[i]-'0';
                y=0;
                i--;
            }
            else if(j>=0&&i<0)
            {
                y=b[j]-'0';
                j--;
                x=0;
            }
            else if(carry==0)
            return s;

            if(x==1&&y==1&&carry==1)//111
            {
                s+='1';
                carry=1;
            }
            else if(x==1&&y==1&&carry==0)//110
            {
                s+='0';
                carry=1;
            }
            else if(x==1&&y==0&&carry==1)//101
            {
                s+='0';
                carry=1;
            }
            else if(x==0&&y==1&&carry==1)//011
            {
                s+='0';
                carry=1;
            }
            else if(x==1&&y==0&&carry==0)//100
            {
                s+='1';
                carry=0;
            }
            else if(x==0&&y==1&&carry==0)//010
            {
                s+='1';
                carry=0;
            }
            else if(x==0&&y==0&&carry==1)//001
            {
                s+='1';
                carry=0;
            }
            else
            {
                s+='0';
                carry=0;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};