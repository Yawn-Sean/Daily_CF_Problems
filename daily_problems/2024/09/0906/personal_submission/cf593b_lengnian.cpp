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
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    auto x = new pii[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[i] = pii({a * x1 + b, a * x2 + b});
    }

    sort(x, x + n);
    for (int i = 1; i < n; i++)
    {
        if (x[i - 1].se > x[i].se)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
