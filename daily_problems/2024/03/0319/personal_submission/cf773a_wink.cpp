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
    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    if (p == 0)
    {
        cout << (x == 0 ? 0 : -1) << '\n';
        return;
    }
    if (p == q)
    {
        cout << (x == y ? 0 : -1) << '\n';
        return;
    }

    // 假设最后的总次数是 k*q，那么成功提交的次数是 p*k，不成功提交的次数是 k*q-p*k
    // 本身成功提交数量为 x，不成功为 y-x
    // 左右两边只能变大不能变小，所以判断一下是否合法，找到最小的合法的 t
    auto check = [&](ll k)
    {
        return p * k >= x && q * k - p * k >= y - x;
    };
    ll l = 1, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r * q - y << '\n';
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
