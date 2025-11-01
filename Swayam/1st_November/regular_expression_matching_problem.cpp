#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[n][m];
    }
};

// Driver Code
int main()
{

    // Testcases
    vector<string> s = {"aa", "aa", "ab"};
    vector<string> p = {"a", "a*", ".*"};

    for (int i = 0; i < s.size(); ++i)
    {
        cout << "s = " << s[i] << ", p = " << p[i] << " Matching: " << Solution().isMatch(s[i], p[i]) << endl;
    }
    return 0;
}