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
const int N = 100005;
int a[N], b[N], c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                if (i - c[j] > b[i])
                    ans++;
                if (j != a[i] / j && i - c[a[i] / j] > b[i])
                    ans++;
            }
        }

        cout << ans << "\n";
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                c[j] = i, c[a[i] / j] = i;
            }
        }
    }
    return 0;
}
