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

    int m;
    cin >> m;

    int mid, sum, ans = -1, l = 1, r = 5e15;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        sum = 0;
        for (int i = 2; i * i * i <= mid; i++)
            sum += mid / (i * i * i);

        if (sum == m)
            ans = mid;
        if (sum >= m)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans;
    return 0;
}
