#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sz(s) ((int)s.size())
#define ms(s, x) memset(s, x, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

// 离线思想。查询较少，将操作反过来进行，看看每个查询对应最初的哪个坐标
void solve()
{
    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    vector<array<int, 3>> que(q);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i)
    {
        int op, l, r;
        cin >> op >> l >> r;
        l--, r--;
        que[i] = {op, l, r};
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        b[i] -= 1;
    }

    reverse(que.begin(), que.end());
    for (auto [op, l, r] : que)
    {
        if (op == 1)
        {
            for (auto &v : b)
            {
                if (v > l && v <= r)
                {
                    v -= 1;
                }
                else if (v == l)
                {
                    v = r;
                }
            }
        }
        else
        {
            for (auto &v : b)
            {

                if (l <= v && v <= r)
                {
                    v = r + l - v;
                }
            }
        }
    }
    for (auto v : b)
    {
        cout << a[v] << " ";
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
