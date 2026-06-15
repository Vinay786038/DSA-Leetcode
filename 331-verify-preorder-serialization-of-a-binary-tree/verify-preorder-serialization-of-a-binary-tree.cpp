class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        stack<string> st;
        string cur="";

        for(int i=0;i<=preorder.size();i++)
        {
            if(i==preorder.size() || preorder[i]==',')
            {
                st.push(cur);

                while(st.size()>=3)
                {
                    string a=st.top(); st.pop();
                    string b=st.top(); st.pop();
                    string c=st.top(); st.pop();

                    if(a=="#" && b=="#" && c!="#")
                    {
                        st.push("#");
                    }
                    else
                    {
                        st.push(c);
                        st.push(b);
                        st.push(a);
                        break;
                    }
                }

                cur="";
            }
            else
            {
                cur+=preorder[i];
            }
        }

        return st.size()==1 && st.top()=="#";
    }
};