class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>ans(2);
        ans[0]=(double)(celsius+273.15);
        ans[1]=(double)((celsius*1.80)+32.00);
        return ans;
    }
};