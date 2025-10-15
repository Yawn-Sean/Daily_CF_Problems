#include <bits/stdc++.h>
#define int __int128

using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
int ans;
using i128 = __int128;

istream &operator>>(istream &is, i128 &x)
{
    string s;
    is >> s;
    bool neg = false;
    x = 0;
    for (char c : s)
    {
        if (c == '-')
            neg = true;
        else
            x = x * 10 + (c - '0');
    }
    if (neg)
        x = -x;
    return is;
}

ostream &operator<<(ostream &os, i128 x)
{
    if (x == 0)
        os << 0;
    else
    {
        string s, t;
        if (x < 0)
            x = -x, t = "-";
        while (x)
            s.push_back('0' + x % 10), x /= 10;
        reverse(s.begin(), s.end());
        os << t << s;
    }
    return os;
}

i128 abs(i128 &x) { return x > 0 ? x : -x; }
void check(int l, int r, int num)
{
    int res = 1ll;
    int cnt = 0ll;
    while (l <= r)
    {
        while (res <= l)
        {
            res = res * num;
            cnt++;
        }
        res = min(res - 1ll, r);
        ans = ans + (res - l + 1ll) % mod * (cnt - 1ll) % mod;
        ans %= mod;
        l = res + 1ll;
    }
}
void solve()
{
    int l, r;
    ans = (int)0;
    cin >> l >> r;
    int i = l;
    while (i <= r)
    {
        int num = 0ll;
        for (num = 62; num >= 0; num--)
        {
            if ((i >> num) & 1ll)
            {
                break;
            }
        }
        int j = min(((int)1 << (num + (int)1)) - (int)1, r);
        check(i, j, num);
        i = j + 1ll;
    }
    cout << (long long)ans << endl;
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