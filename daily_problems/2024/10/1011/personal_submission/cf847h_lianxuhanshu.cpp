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
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

int a[N];
int pre[N], suf[N];
LL s_pre[N], s_suf[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    pre[1] = a[1];
    s_pre[1] = pre[1] - a[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = max(pre[i - 1] + 1, a[i]);
        s_pre[i] = s_pre[i - 1] + pre[i] - a[i];
    }

    suf[n] = a[n];
    s_suf[n] = suf[n] - a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1] + 1, a[i]);
        s_suf[i] = s_suf[i + 1] + suf[i] - a[i];
    }

    LL ans = s_suf[1];
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, s_pre[i - 1] + s_suf[i + 1] + max(pre[i], suf[i]) - a[i]);
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
