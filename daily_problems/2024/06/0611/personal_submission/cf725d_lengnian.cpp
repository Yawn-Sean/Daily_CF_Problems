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

    i64 x, y;
    cin >> x >> y;

    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<int> st(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        st[i] = i;
    }

    sort(st.begin(), st.end(), [&a](int k, int l)
         { return a[k] < a[l]; });

    vector<int> sort_a(n - 1);
    vector<int> sort_b(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        sort_a[i] = a[st[i]];
        sort_b[i] = b[st[i]];
    }

    priority_queue<int, vector<int>, greater<int>> hpq;

    int p = n - 2;

    while (p >= 0 && sort_a[p] > x)
    {
        hpq.push(sort_b[p] - sort_a[p] + 1);
        --p;
    }

    int res = hpq.size() + 1;
    while (!hpq.empty() && x >= hpq.top())
    {
        x -= hpq.top();
        hpq.pop();

        while (p >= 0 && sort_a[p] > x)
        {
            hpq.push(sort_b[p] - sort_a[p] + 1);
            --p;
        }
        res = min(res, (int)hpq.size() + 1);
    }

    cout << res << endl;

    return 0;
}
