class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed)
    {
        int n=releaseTimes.size();
        char c;
        int maxx=releaseTimes[0];
        c=keysPressed[0];
        for(int i=1;i<n;i++)
        {
            if(releaseTimes[i]-releaseTimes[i-1]==maxx)
            {
                if(keysPressed[i]>c)
                c=keysPressed[i];
            }
            if(releaseTimes[i]-releaseTimes[i-1]>maxx)
            {
                maxx=releaseTimes[i]-releaseTimes[i-1];
                c=keysPressed[i];
            }
        }
        return c;
    }
};