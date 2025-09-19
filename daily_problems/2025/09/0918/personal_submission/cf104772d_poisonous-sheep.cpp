#include <bits/stdc++.h>

#define int long long
#define ld long double
#define ll long long
#define lowbit(x) x & -x

using namespace std;

const int N = 130;
const int mod = 1e9 + 7;
const int INF = 1e18;

#define endl '\n'
#define rep(l, r) for (int i = l; i <= r; i++)
#define lep(r, l) for (int i = r; i >= l; i--)

using pii = pair<int, int>;
using i64 = int64_t;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define ok cout << "YES\n"
#define no cout << "NO\n"


void solve()
{
    int d, saved;
    cin >> d;
    saved = d;
    while (d % 2 == 0) d /= 2;
    while (d % 5 == 0) d /= 5;

    int cur = 0, tot = 0;

    for (int i = 1; i <= 1000000; i ++) {
        cur = (10ll * cur + 9) % d;
        tot = (tot + 9) % saved;

        if (cur == 0 && tot == 0){
            cout << string(i, '9') << string(10, '0');
            return;
        }
            
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
