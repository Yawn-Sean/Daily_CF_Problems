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

void solve()
{
    string s;
    cin >> s;
    
    int res = 0;
    int n = s.size();
    int mid = n + 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; i + j + j <= n; j++)
        {
            if (s[i - 1] == s[i + j - 1] && s[i + j - 1] == s[i + j + j - 1])
            {
                mid = min(mid, i + j + j);
                break;
            }
        }

        res += n - mid + 1;
    }

    cout << res << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    while (T--)
        solve();
    return 0;
}
