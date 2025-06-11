#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int mod = 1000000007;

vector<int> z_func(const vector<int> &s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i)
    {
        z[i] = max(0, min(z[i - left], right - i));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
        if (i + z[i] > right)
        {
            left = i;
            right = i + z[i];
        }
    }
    return z;
}

int main()
{
    // freopen("../input.txt", "r", stdin);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        nums[i] = s[i] - '0';
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        auto z = z_func(vector<int>(nums.begin() + i, nums.end()));
        for (int L = 1; L <= n / 2; ++L)
        {
            if (i + L >= n)
                break;
            if (z[L] < L && i + z[L] + L < n && nums[i + z[L]] < nums[i + z[L] + L])
            {
                f[i][L] = 1;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> pre_sum(n + 1, vector<int>(n + 1, 0));

    for (int k = 1; k <= n; ++k)
    {
        for (int j = 0; j < k; ++j)
        {
            if (nums[j] == 0)
            {
                pre_sum[k][j + 1] = (pre_sum[k][j] + dp[j][k]) % mod;
                continue;
            }

            if (j == 0)
            {
                dp[j][k] = 1;
            }
            else
            {
                int i = max(j - (k - j), -1);
                if (k - j == j - i && i >= 0 && f[i][k - j])
                {
                    dp[j][k] += dp[i][j];
                    dp[j][k] %= mod;
                }
                if (i + 1 < j)
                {
                    dp[j][k] += (pre_sum[j][j] - pre_sum[j][i + 1] + mod) % mod;
                    dp[j][k] %= mod;
                }
            }

            pre_sum[k][j + 1] = (pre_sum[k][j] + dp[j][k]) % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + dp[i][n]) % mod;
    }

    cout << ans << endl;

    return 0;
}
