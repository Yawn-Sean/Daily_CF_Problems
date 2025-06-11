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
    int n, s;
    cin >> n >> s;

    vector<int> add(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        u--;
        v--;
        add[u]++;
        add[v]++;
    }

    int r = count(all(add), 1);

    double res = 2.0 * s / r;

    cout << fixed << setprecision(10) << res << "\n";

    return 0;
}
