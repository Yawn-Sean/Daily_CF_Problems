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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h;
    cin >> n >> h;
    vector<pii> x;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x.pb({a, b});
    }

    sort(all(x));

    int l[n]{};
    int r[n]{};

    for (int i = 1; i <= n; i++)
    {

        l[i] = x[i - 1].fi;
        r[i] = x[i - 1].se;
    }
    int s[n]{};
    for (int i = 1; i <= n; i++)
    {

        s[i] = s[i - 1] + r[i] - l[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int p = i, q = n;
        while (p < q)
        {
            int mid = (p + q + 1) >> 1;
            if (r[mid] - l[i] < s[mid] - s[i - 1] + h)
            {
                p = mid;
            }
            else
            {
                q = mid - 1;
            }
        }

        ans = max(ans, h + s[p] - s[i - 1]);
    }

    cout << ans << "\n";
    return 0;
}
