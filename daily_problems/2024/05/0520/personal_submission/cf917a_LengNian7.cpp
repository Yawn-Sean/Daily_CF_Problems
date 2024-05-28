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
    int n = s.length();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        int right = 0;
        for (int j = i; j < n; j++)
        {
            if (s[j] == '(')
            {
                cur += 1;
            }
            else if (s[j] == ')')
            {
                cur -= 1;
            }
            else
            {
                cur -= 1;
                right += 1;
            }
            if (cur < 0)
            {
                if (right == 0)
                    break;
                right -= 1;
                cur += 2;
            }
            if (cur == 0)
            {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
