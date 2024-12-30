void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vv(int, dp, n + 1, n + 1);
    vv(int, f, n + 1, n + 1);
    // dp[i][j]:以i位作为开头，以j位作为结尾的数字作为最后一项的序列个数
    // dp[i][j]+=dp[k][i-1],2*i-j-1<k<=i-1,pre[i-1][j-i-1]
    // f[i][j]=s[i]==s[j+1]?min(f[i+1][j+1]+1,j-i+1):0,i从后往前
    // f[i][j]:i开头，j结尾的子串和后面等长子串的lcp
    rfo(i, n - 1, 0)
    {
        rfo(j, n - 1, i)
        {
            if (i + 1 < n && j + 1 < n)
                f[i][j] = s[i] == s[j + 1] ? min(f[i + 1][j + 1] + 1, j - i + 1) : 0;
        }
    }

    fo(i, 0, n)
    {
        int sum = 0;
        fo(j, i, n)
        {
            if (i == 0)
            {
                dp[0][j] = 1;
                continue;
            }
            if (s[i] == '0')
            {
                continue;
            }
            if (2 * i - j - 1 >= 0)
            {
                int k = 2 * i - j - 1;
                if (f[k][i - 1] < j - i + 1 && s[i + f[k][i - 1]] > s[k + f[k][i - 1]])
                {
                    int tmp = dp[k][i - 1];
                    add(sum, tmp);
                    dp[i][j] = sum;
                }
                else
                {
                    dp[i][j] = sum;
                    add(sum, dp[k][i - 1]);
                }
            }
            else
            {
                dp[i][j] = sum;
            }
        }
    }
    int ans = 0;
    fo(i, 0, n)
    {
        // debug(dp[i][n - 1]);
        add(ans, dp[i][n - 1]);
    }
    ca;
}
