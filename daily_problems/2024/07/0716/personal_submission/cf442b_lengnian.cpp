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
const int N = 110;
double a[N];

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    double ans = 0, res = 1;
    for (int i = n; i; i--)
        if (ans < res)
        {
            ans = ans * (1 - a[i]) + res * a[i];
            res *= 1 - a[i];
        }
    printf("%.12lf\n", ans);
    return 0;
}
