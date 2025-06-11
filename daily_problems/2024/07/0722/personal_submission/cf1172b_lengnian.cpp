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

const int N = 2e5 + 10;
const int mod = 998244353;
int a[N], b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] * i % mod;
    }

    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        b[x]++;
        b[y]++;
    }

    int res = n;
    for (int i = 1; i <= n; i++)
    {
        res = res * a[b[i]] % mod;
    }

    cout << res << "\n";
    return 0;
}
