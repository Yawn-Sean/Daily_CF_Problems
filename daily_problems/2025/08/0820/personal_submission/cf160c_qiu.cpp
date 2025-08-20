#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
vector<PII> e[N];
int dp[N][33];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x, y;
    k--;
    for (x = 0; x < n;)
    {
        y = 1;
        while (x + y < n && a[x] == a[x + y])
            y++;
        if (y * n > k)
        {
            break;
        }
        else
        {
            k -= y * n;
        }
        x += y;
    }
    cout << a[x] << ' ' << a[k / y] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
