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

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;
    int l = 0, r = 0;

    for (auto num : nums)
    {
        if (num == 0)
        {
            l = max(l, 0LL);
            if (r < 0)
            {
                r = m;
                ans += 1;
            }
        }
        else
        {
            l += num;
            r += num;
            r = min(r, m);
            if (l > m)
            {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
