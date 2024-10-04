#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, vector<int>> mp;
    mp['W'] = {1};
    mp['L'] = {-1};
    mp['D'] = {0};
    mp['?'] = {-1, 0, 1};


    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -2));
    dp[0][k] = 0;

    for (int i = 0; i < n; i ++) {
        for (auto dj: mp[s[i]]) {
            for (int j = 1; j < 2 * k; j ++) {
                if (dp[i][j] != -2) {
                    dp[i + 1][j + dj] = dj;
                }
            }
        }
    }

    int cur;
    if (dp[n][0] != -2) cur = 0;
    else if (dp[n][2 * k] != -2) cur = 2 * k;
    else return cout << "NO", 0;

    map<int, char> status;

    status[-1] = 'L';
    status[0] = 'D';
    status[1] = 'W';

    vector<char> ans;

    for (int i = n; i > 0; i --) {
        ans.emplace_back(status[dp[i][cur]]);
        cur -= dp[i][cur];
    }

    reverse(ans.begin(), ans.end());
    for (auto &x: ans) cout << x;

    return 0;
}