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

    int l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;

    int g = __gcd(t1, t2), x = ((l2 - l1) % g + g) % g;
    cout << max(0ll, max(min(r1 - l1, r2 - l2 - g + x), min(r1 - l1 - x, r2 - l2)) + 1);
    return 0;
}
