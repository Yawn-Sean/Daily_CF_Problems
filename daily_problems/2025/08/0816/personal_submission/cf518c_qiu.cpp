#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> g(n + 1, 0), pos(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        pos[g[i]] = i;
    }
    int ans = 0;
    while (m--)
    {
        int b;
        cin >> b;
        int num = (pos[b] - 1) / k;
        ans++;

        ans += num;
        num = pos[b];
        int a = g[num - 1];
        if (num != 1)
        {
            swap(g[num], g[num - 1]);
            swap(pos[a], pos[b]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
