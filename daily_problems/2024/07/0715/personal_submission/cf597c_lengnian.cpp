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

const int N = 200020;
i64 t[N][12];
inline int lowbit(int x) { return x & (-x); }
void init(int x, int y, i64 d)
{
    for (x; x <= 100010; x += lowbit(x))
        t[x][y] += d;
}
inline i64 sum(int x, int y)
{
    i64 res = 0;
    for (x; x > 0; x -= lowbit(x))
        res += t[x][y];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, m;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        m = max(m, a);
        init(a, 1, 1);
        if (a == 1)
            continue;
        for (int j = 2; j <= k + 1; j++)
        {
            i64 tt = sum(a - 1, j - 1);
            init(a, j, tt);
        }
    }

    cout << sum(100010, k + 1) << "\n";
    return 0;
}
