class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        double ans;
        int hourr=hour%12;
        int minutess=minutes%60;
        double minuteang=minutess*6;
        double hourang=hourr*30+minuteang/12;
        ans=abs(minuteang-hourang);
        if(ans>180)
        return 360-ans;
        return ans;

        
    }
};