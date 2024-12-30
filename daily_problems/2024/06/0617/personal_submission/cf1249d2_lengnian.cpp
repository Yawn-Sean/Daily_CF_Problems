#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

const int MAXD = 2e5 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    vector<vector<int>> s(2e5 + 10), t(2e5 + 10);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        --l[i];
        s[l[i]].pb(i);
        t[r[i]].pb(i);
    }

    set<pii> segs;

    vector<int> res;
    for (int i = 0; i <= MAXD; i++)
    {
        for (auto x : t[i])
        {
            segs.erase({r[x], x});
        }
        for (auto x : s[i])
        {
            segs.emplace(r[x], x);
            if (segs.size() > k)
            {
                auto j = --segs.end();
                res.pb(j->second);
                segs.erase(j);
            }
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] + 1 << " \n"[i == res.size() - 1];
    }
    return 0;
}
