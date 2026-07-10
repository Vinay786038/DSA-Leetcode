class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int ans=0;
        ans=(abs(ax2-ax1)*abs(ay2-ay1))+(abs(bx2-bx1)*abs(by2-by1));
        int left=max(ax1,bx1);
        int right=min(ax2,bx2);
        int bottom=max(ay1,by1);
        int top=min(ay2,by2);
        int overlap=0;
        if(left<right&&bottom<top)
        {
            overlap=(right-left)*(top-bottom);
        }
        return ans-overlap;

        
    }
};