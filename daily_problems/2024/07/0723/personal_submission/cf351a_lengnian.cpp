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

const int N = 4010;
int pos[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    int sum = 0, b = 0;
    for (int i = 1; i <= 2n; i++)
    {
        double x;
        cin >> x;
        pos[i] = (ll)(1000.0 * x + .5) % 1000ll;
        if (pos[i] == 0)
            cnt++;
        sum += pos[i];
    }
    int res = 1e15;
    for (int i = max(n - cnt, 0); i <= n && i <= n + n - cnt; i++)
    {
        int val = abs(sum - 1000ll * i);
        res = min(res, val);
    }

    cout << res * 0.001;

    return 0;
}
