class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int MAR, DAR, MAL, DAL, MBR, DBR, MBL, DBL;
        MAR = stoi(arriveAlice.substr(0, 2));
        DAR = stoi(arriveAlice.substr(3, 2));
        MAL = stoi(leaveAlice.substr(0, 2));
        DAL = stoi(leaveAlice.substr(3, 2));
        MBR = stoi(arriveBob.substr(0, 2));
        DBR = stoi(arriveBob.substr(3, 2));
        MBL = stoi(leaveBob.substr(0, 2));
        DBL = stoi(leaveBob.substr(3, 2));
        int AM = max(MAR, MBR);
        int AD = (MAR > MBR) ? DAR :(MAR < MBR) ? DBR : max(DAR, DBR);
        int LM = min(MAL, MBL);
        int LD = (MAL < MBL) ? DAL :(MAL > MBL) ? DBL : min(DAL, DBL);
        if ((AM > LM) || (AM == LM && AD > LD)) {
            return 0;
        }
        int ans = 0;
        vector<int> months;
        months.push_back(31);
        months.push_back(28);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        int sum=0;
        for(int i=AM;i<LM;i++)
        {
            sum+=months[i-1];
        }
        return sum+LD-AD+1;
    }
};