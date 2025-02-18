#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k;

int a[N];
vector<int> g[N];
LL f[N], s[N];

void dp(int u, int fa, LL &ans)
{
    f[u] = a[u], s[u] = -1e18;
    vector<LL> nums;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        dp(v, u, ans);
        f[u] += f[v];
        s[u] = max(s[u], s[v]);
        nums.push_back(s[v]);
    }
    s[u] = max(s[u], f[u]);
    sort(nums.begin(), nums.end(), [&](LL A, LL B)
         { return A > B; });

    if (nums.size() >= 2)
        ans = max(ans, nums[0] + nums[1]);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LL ans = -1e18;
    dp(1, -1, ans);
    if (ans == -1e18)
        cout << "Impossible" << '\n';
    else
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
