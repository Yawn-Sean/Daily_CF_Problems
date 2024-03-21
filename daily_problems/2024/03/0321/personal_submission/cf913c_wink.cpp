#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sz(s) ((int)s.size())
#define ms(s, x) memset(s, x, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

void solve()
{
    int n, s;
    cin >> n >> s;

    vector<ll> c(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }
    // 容量更大的一定可以被容量小的凑出来，所以考虑容量大的被容量小的替换是否更优
    for (int i = 0; i < n - 1; ++i)
    {
        c[i + 1] = min(c[i + 1], c[i] * 2);
    }

    ll ans = 4e18;
    ll sum = 0;

    // 因为上面经过贪心考虑，买容量大的性价比一定更高，能尽量买就尽量买
    // 买了之后可能有剩余空间，考虑留给体积小的来买还是直接买多一瓶当前的，选个更优抉择
    for (int i = n - 1; i >= 0; i--)
    {
        ll need = s / (1 << i);
        sum += need * c[i];
        s -= (need << i);
        ans = min(ans, sum + (s > 0) * c[i]);
    }

    cout << ans << '\n';
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
