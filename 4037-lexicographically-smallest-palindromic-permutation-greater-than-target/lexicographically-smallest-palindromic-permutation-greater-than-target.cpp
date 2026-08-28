class Solution {
public:

    string makePalindrome(string left, char mid) {

        string right = left;
        reverse(right.begin(), right.end());

        return left +
               (mid == '#' ? "" : string(1, mid)) +
               right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Frequency of left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
        }

        int m = n / 2;

        string targetLeft = target.substr(0, m);

        // --------------------------------------------------
        // CASE 1:
        // Left half exactly same as target's left half
        // --------------------------------------------------

        vector<int> rem = half;
        string left = "";

        bool possible = true;

        for (int i = 0; i < m; i++) {

            int c = targetLeft[i] - 'a';

            if (rem[c] == 0) {
                possible = false;
                break;
            }

            rem[c]--;
            left += targetLeft[i];
        }

        if (possible) {

            string candidate = makePalindrome(left, mid);

            if (candidate > target) {
                return candidate;
            }
        }

        // --------------------------------------------------
        // CASE 2:
        // Make left half greater than targetLeft
        //
        // Start from RIGHT because we want the smallest
        // possible lexicographical answer.
        // --------------------------------------------------

        for (int pos = m - 1; pos >= 0; pos--) {

            vector<int> remaining = half;

            string prefix = "";

            bool possible = true;

            // Match target before pos
            for (int i = 0; i < pos; i++) {

                int c = targetLeft[i] - 'a';

                if (remaining[c] == 0) {
                    possible = false;
                    break;
                }

                remaining[c]--;
                prefix += targetLeft[i];
            }

            if (!possible) {
                continue;
            }

            int targetChar = targetLeft[pos] - 'a';

            // Choose smallest character greater than target[pos]
            for (int c = targetChar + 1; c < 26; c++) {

                if (remaining[c] == 0) {
                    continue;
                }

                string candidateLeft = prefix;

                candidateLeft += char('a' + c);

                remaining[c]--;

                // Fill remaining characters in smallest order
                for (int x = 0; x < 26; x++) {

                    candidateLeft +=
                        string(remaining[x],
                               char('a' + x));
                }

                return makePalindrome(candidateLeft, mid);
            }
        }

        return "";
    }
};