class Solution {
public:
    long long gcd(long long first, long long second)
    {
        while (second != 0)
        {
            long long temp = second;
            second = first % second;
            first = temp;
        }
        return first;
    }

    string smallestNumber(string num, long long t)
    {
        long long remfactor = t;

        for (int i = 2; i <= 9; i++)
        {
            while (remfactor % i == 0)
            {
                remfactor /= i;
            }
        }

        if (remfactor > 1)
        {
            return "-1";
        }

        int len = num.length();

        vector<long long> rfactor(len + 1);
        rfactor[0] = t;

        int fZeroInd = len - 1;

        for (int i = 0; i < len; i++)
        {
            if (num[i] == '0')
            {
                fZeroInd = i;
                break;
            }

            rfactor[i + 1] = rfactor[i] / gcd(rfactor[i], (long long)(num[i] - '0'));
        }

        if (rfactor[len] == 1)
        {
            return num;
        }

        for (int i = fZeroInd; i >= 0; i--)
        {
            while (++num[i] <= '9')
            {
                long long curneed = rfactor[i] / gcd(rfactor[i], (long long)(num[i] - '0'));

                int condidigit = 9;

                for (int j = len - 1; j > i; j--)
                {
                    while (curneed % condidigit != 0)
                    {
                        condidigit--;
                    }

                    curneed /= condidigit;
                    num[j] = char('0' + condidigit);
                }

                if (curneed == 1)
                {
                    return num;
                }
            }
        }

        string ans = "";
        long long rem = t;

        for (int digit = 9; digit >= 2; digit--)
        {
            while (rem % digit == 0)
            {
                ans.push_back(char('0' + digit));
                rem /= digit;
            }
        }

        int extraone = max(len + 1 - (int)ans.length(), 0);

        while (extraone--)
        {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};