#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<PII> ve(n);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        ve[i - 1] = {a, b};
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++)
    {
        pq.push(0);
    }
    int l = 0;
    while (!pq.empty())
    {
        if (l >= n)
        {
            return;
        }
        auto v = pq.top();
        pq.pop();
        int t = max(v, ve[l].first);
        cout << t + ve[l].second << endl;
        pq.push(t + ve[l].second);
        l++;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    // cin >> T;
    while (T--)
        solve();
    return 0;
}
