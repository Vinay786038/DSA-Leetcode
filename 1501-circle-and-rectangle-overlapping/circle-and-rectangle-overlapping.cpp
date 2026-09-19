class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int distx;
        distx=min(abs(x1-xCenter),abs(x2-xCenter));
        if(xCenter>=x1&&xCenter<=x2)
        {
            distx=0;
        }

        int disty=min(abs(y1-yCenter),abs(y2-yCenter));
        if(yCenter>=y1&&yCenter<=y2)
        {
            disty=0;
        }
        if(distx*distx+disty*disty<=radius*radius)//x^2+y^2=r^2
        {
            return true;
        }
        return false;



    }
};