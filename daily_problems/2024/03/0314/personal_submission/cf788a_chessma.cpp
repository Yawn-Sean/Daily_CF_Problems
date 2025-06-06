#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define nn "\n"
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const int inff = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll mm = 0, sum = 0, ans = -inf;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        int ng = (i % 2) ? -1 : 1;
        if (i > 1) sum += abs(a[i] - a[i - 1]) * ng;
        ans = max(ans, sum - mm);
        mm = min(mm, sum);
    }
    mm = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        int ng = (i % 2) ? 1 : -1;
        if (i > 1) sum += abs(a[i] - a[i - 1]) * ng;
        ans = max(ans, sum - mm);
        mm = min(mm, sum);
    }
    cout << ans << nn;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
