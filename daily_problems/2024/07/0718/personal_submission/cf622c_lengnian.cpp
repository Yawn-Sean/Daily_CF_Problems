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

const int N = 1e6 + 10;
int a[N], b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] == a[i - 1] ? b[i - 1] : i - 1;
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (a[r] != x)
        {
            cout << r << "\n";
        }
        else if (b[r] >= l)
        {
            cout << b[r] << "\n";
        }
        else
            cout << "-1" << "\n";
    }
    return 0;
}
