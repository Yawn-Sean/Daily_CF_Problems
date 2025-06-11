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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<pii, int>> a;
    multiset<int> s;
    set<pii> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.pb({{y, x}, i});
    }

    sort(all(a));

    i64 ans = 0, t = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(a[i].fi.se);
        if (s.size() < k)
        {
            continue;
        }
        if (s.size() > k)
        {
            auto it = s.end();
            it--;
            s.erase(it);
        }

        int d = a[i].fi.fi - *(s.rbegin()) + 1;
        if (d > ans)
        {
            ans = d;
            t = i;
        }
    }

    cout << ans << "\n";

    for (int i = n - 1; i >= t; i--)
    {
        st.insert({a[i].fi.se, a[i].se});
        if (st.size() > k)
        {
            auto it = st.end();
            it--;
            st.erase(it);
        }
    }

    for (auto it : st)
    {
        cout << it.se + 1 << " ";
    }

    cout << "\n";
    return 0;
}
