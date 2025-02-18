#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 0 ? 998244353 : 1e9 + 7;
const int N = 1e5 + 5;
const int inf = 1e9;
// #define int ll
struct node
{
    int l, r;
    bool operator<(const node &a) const
    {
        return l == a.l ? r < a.r : l < a.l;
    }
};
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    // q1:结束使用的TV  q2:还在使用的TV
    for (int i = 0; i < n; i++)
    {
        auto [l, r] = a[i];
        while (!q2.empty() && q2.top() < l)
        {
            q1.push(q2.top());
            q2.pop();
        }
        if (!q1.empty())
        {

            int t = q1.top();
            q1.pop();
            ans += 1ll * min(1ll*(l-t)*y,1ll*x)+1ll*(r-l)*y;
        
        }
        else
        {
            ans += x + 1ll * (r - l) * y;
        }
        ans %= mod;
        q2.push(r);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //  cin>>t;
    while (t--)
    {
        solve();
    }
}
