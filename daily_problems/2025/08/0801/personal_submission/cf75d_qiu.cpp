#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
const int N = 5000 + 10, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ve(n + 1), tot(n + 1, 0), pre(n + 1, -1e9), sur(n + 1, -1e9), maxnum(n + 1, -1e9);
    int ans = -1e9;
    for (int i = 1; i <= n; i++)
    {
        vector<int> temp;
        int k;
        cin >> k;
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
            sum += a;
            pre[i] = max(pre[i], sum);
        }
        sum = 0;
        for (int j = k - 1; j >= 0; j--)
        {
            int a = temp[j];
            sum += a;
            sur[i] = max(sur[i], sum);
        }
        tot[i] = sum;
        sum = 0;
        for (int j = k - 1; j >= 0; j--)
        {
            sum = max(0LL, sum) + temp[j];
            maxnum[i] = max(maxnum[i], sum);
        }
    }

    int w = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        ans = max(ans, max(pre[t], sur[t]));
        ans = max(ans, pre[t] + w);
        ans = max(ans, maxnum[t]);
        w = max(w + tot[t], sur[t]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
