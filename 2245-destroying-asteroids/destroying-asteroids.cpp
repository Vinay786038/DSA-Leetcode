class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        sort(asteroids.begin(),asteroids.end());
        long long currmass=mass;
        for(int x:asteroids)
        {
            if(currmass<x)
            return false;
            currmass+=x;
        }
        return true;
    }
};