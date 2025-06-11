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
    int n, x;
    cin >> n >> x;

    vector<int> pos;
    pos.pb(x);
    pos.pb(x);

    int res = 0;
    res += x;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        res += l;
        pos.pb(l);
        pos.pb(r);
        sort(all(pos));

        res = res - 2 * pos[0] - (pos[1] - pos[0]) + pos[1];
        pos.pop_back();
        pos.erase(pos.begin());
    }

    cout << res - pos[0];
    return 0;
}
