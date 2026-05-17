class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        int st0 = 0, st1 = 0;

        for(int x : students)
        {
            if(x == 0)
            st0++;
            else
            st1++;
        }

        for(int x : sandwiches)
        {
            if(x == 0)
            {
                if(st0 == 0)
                return st1;

                st0--;
            }
            else
            {   
                if(st1 == 0)
                return st0;

                st1--;
            }
        }

        return 0;

    }
};