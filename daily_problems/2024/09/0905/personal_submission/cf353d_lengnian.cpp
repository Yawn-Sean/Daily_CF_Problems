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
    string s;
    cin >> s;
    int ans = 0, a = 0, b = 0;
    for (auto ch : s)
    {
        if (ch == 'M')
        {
            a++;
            if (b > 0)
                b--;
        }
        else if (a > 0)
            ans = max(ans, a + b), b++;
    }

    cout << ans;
    return 0;
}
