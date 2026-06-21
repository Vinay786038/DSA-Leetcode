class Solution {
public:
    int maxDistance(string moves){
        int x=0;
        int y=0;
        int n=moves.size();
        int blanks=0;
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
                y++;
            else if(moves[i]=='D')
                y--;
            else if(moves[i]=='R')
                x++;
            else if(moves[i]=='L')
                x--;
            else
            {
                blanks++;
            }
        }
        int ans=abs(x-0)+abs(y-0)+blanks;
        return ans;
    }
};