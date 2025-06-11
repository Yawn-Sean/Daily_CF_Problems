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

struct SegTree
{
    vi t;
    int n;

    void build(int sz)
    {
        n = sz;
        t.resize(n * 2);
    }

    void upd(int i, int x)
    {
        i += n;
        for (t[i] = max(t[i], x); i > 1; i >>= 1)
            t[i >> 1] = max(t[i], t[i ^ 1]);
    }

    int get(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(res, t[--r]);
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    SegTree st;
    st.build(n + 1);
    vector<int> dp(n);
    vector<int> stk;

    for (int i = n - 1; i >= 0; i--)
    {
        int res = st.get(a[i], n + 1);
        st.upd(a[i], res + 1);
        dp[i] = res + 1;
        while (stk.size() && a[stk.back()] < a[i])
        {
            st.upd(a[stk.back()], dp[stk.back()] + 1);
            stk.pop_back();
        }

        stk.push_back(i);
    }

    cout << st.get(0, n + 1) << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
