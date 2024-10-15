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

    int n, b;
    cin >> n >> b;

    vector<int> a(n, -1);
    deque<pii> q;
    for (int i = 0; i < n; i++)
    {
        int x, d;
        cin >> x >> d;
        while (!q.empty() && q.front().se <= x)
        {
            a[q.front().fi] = q.front().se;
            q.pop_front();
        }
        if (q.empty())
        {
            q.pb({i, x + d});
        }
        else if (q.size() <= b)
            q.pb({i, q.back().se + d});
    }
    while (!q.empty())
    {
        a[q.front().fi] = q.front().se;
        q.pop_front();
    }
    for (auto i : a)
        cout << i << ' ';
}
