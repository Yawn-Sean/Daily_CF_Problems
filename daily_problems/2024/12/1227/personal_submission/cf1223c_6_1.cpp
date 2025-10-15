#include <bits/stdc++.h>
#define int long long
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
using namespace std;

const int N = 2e5 + 10;

int v[N], st[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + 1 + n);
    int x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    int sum = 0;
    auto check = [&](int mid)
    {
        int na = 0, nb = 0, nab = 0;
        for (int i = 1; i <= mid; i++)
        {
            if (i % a == 0 && i % b == 0)
                nab++;
            else if (i % a == 0)
                na++;
            else if (i % b == 0)
                nb++;
            st[i] = 0;
        }
        int ridx = n;
        int res = 0;
        for (int i = 1; i <= mid; i++)
        {
            if (nab)
            {
                res += v[ridx--] / 100 * (x + y);
                nab--;
            }
            else
            {
                if (x > y)
                {
                    if (na)
                        res += v[ridx--] / 100 * x, na--;
                    else if (nb)
                        res += v[ridx--] / 100 * y, nb--;
                }
                else
                {
                    if (nb)
                        res += v[ridx--] / 100 * y, nb--;
                    else if (na)
                        res += v[ridx--] / 100 * x, na--;
                }
            }
        }
        return res >= k;
    };
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;

        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (check(r))
        cout << r << endl;
    else
        cout << -1 << endl;
}

signed main()
{
    IOS int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
