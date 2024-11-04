#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int M = 1e7 + 5;
ll cnt[M]{};
void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll cur = 0;
    for (int i = 1e7; i > 0; i--)
    {
        cur += cnt[i];
        if (2 * i + 1 < M)//3->1 2->1 1 1 先拆2k+1
        {
            cur += cnt[2 * i + 1];
            cnt[i] += cnt[2 * i + 1];
            cnt[i + 1] += cnt[2 * i + 1];
        }
        if (i * 2 < M)
        {
            cur += cnt[i * 2];
            cnt[i] += 2 * cnt[i * 2];
        }
        if (cur >= k)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
