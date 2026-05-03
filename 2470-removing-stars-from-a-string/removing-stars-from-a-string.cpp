class Solution {
public:
    string removeStars(string s) 
    {
        string str;
        stack<char>st;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            if(st.empty()==1)
            st.push(s[i]);
            else if(s[i]=='*'&&st.empty()!=1)
            {
                st.pop();
            }
            else
            st.push(s[i]);
            i++;
        }
        while(st.empty()!=1)
        {
            str+=st.top();
            st.pop();
        }
        int left=0;
        int right=str.size()-1;
        while(left<right)
        {
            char temp=str[left];
            str[left]=str[right];
            str[right]=temp;
            left++;
            right--;
        }
        return str;

        
    }
};