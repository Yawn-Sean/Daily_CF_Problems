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
const int N = 1e7 + 10, mod = 1e9 + 7;
int n, m, k;

LL cnt[N];
void solve()
{
    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }

    LL cur = 0;
    for (int i = mx; i > 0; i--)
    {
        cur += cnt[i];

        if (i * 2 + 1 <= mx)
        {
            cur += cnt[i * 2 + 1];
            cnt[i] += cnt[i * 2 + 1];
            cnt[i + 1] += cnt[i * 2 + 1];
        }

        if (i * 2 <= mx)
        {
            cur += cnt[i * 2];
            cnt[i] += cnt[i * 2] * 2;
        }

        if (cur >= k)
        {
            cout << i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
