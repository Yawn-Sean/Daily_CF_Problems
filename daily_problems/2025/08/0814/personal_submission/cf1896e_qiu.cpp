#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;
const int N = 2e6 + 10;
struct BIT
{
    int n;
    std::vector<int> tr;

    BIT(int n = 0) { init(n); }

    void init(int n_)
    {
        n = n_;
        tr.assign(n + 1, 0);
    }

    int lowbit(int x) { return x & -x; }

    void update(int x, int k)
    {
        while (x <= n)
        {
            tr[x] += k;
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int s = 0;
        while (x > 0)
        {
            s += tr[x];
            x -= lowbit(x);
        }
        return s;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * 2 + 1, 0), pos(n + 1, 0), l(2 * n + 1, 0), r(2 * n + 1, 0);
    BIT t(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[i] = i;
        if (a[i] >= i)
        {
            r[i] = a[i];
            r[i + n] = a[i] + n;
        }
        else
        {
            r[i] = a[i] + n;
        }
    }

    vector<int> ans(n + 1, 0);
    for (int i = 2 * n; i >= 1; i--)
    {
        if (i <= n)
        {
            ans[a[i]] = r[i] - l[i] - t.query(r[i]);
        }
        if (r[i] == 0)
            continue;
        t.update(r[i], 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}