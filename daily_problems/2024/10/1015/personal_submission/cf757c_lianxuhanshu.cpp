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
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, m, k;

vector<int> g[N];
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int type;
            cin >> type;
            g[type].push_back(i);
        }
    }

    sort(g + 1, g + 1 + m);
    int ans = 1, cur = 1;
    for (int i = 2; i <= m; i++)
    {
        if (g[i] == g[i - 1])
            cur++;
        else
            cur = 1;
        ans = 1ll * ans * cur % mod;
    }
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
