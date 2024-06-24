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

    vector<i64> a(2 * n + 1), b(2 * n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int l = n + x - 1 - i, r = 2 * n - 1 - i;
        b[l]++, b[r + 1]--;
        a[l] -= l, a[r + 1] += l;
    }

    for (int i = 0; i < 2 * n; i++)
    {
        b[i + 1] += b[i], a[i + 1] += a[i];
    }

    vector<i64> ans(n);
    for (int i = 0; i < 2 * n; i++)
    {
        ans[i % n] += 1ll * b[i] * i + a[i];
    }

    auto p = min_element(all(ans));
    cout << *p * 2 << ' ' << (p - ans.begin()) << "\n";
    return 0;
}
