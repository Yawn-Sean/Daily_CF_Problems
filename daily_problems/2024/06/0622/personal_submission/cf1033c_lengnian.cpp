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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++)
    {
        b[a[i]] = i;
    }

    vector<int> dp(n);

    for (int i = n; i > 0; i--)
        for (int j = b[i] % i; j < n; j += i)
        {
            if (a[j] > i && !dp[j])
            {
                dp[b[i]] = 1;
            }
        }

    for (auto &x : dp)
        cout << "BA"[x];

    return 0;
}
