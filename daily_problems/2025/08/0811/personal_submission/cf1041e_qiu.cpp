#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b != n)
            ok = false;
        ve[a]++;
    }
    if (ok == false)
    {
        cout << "NO" << endl;
        return;
    }
    queue<int> node;
    vector<PII> ans;

    for (int i = 1; i <= n; i++)
    {

        // cout << i << ' ' << node.size() << endl;
        if (ve[i] == 0)
            node.push(i);
        if (node.size() + 1 < ve[i] && ve[i])
        {
            cout << "NO" << endl;
            return;
        }
        else if (ve[i])
        {
            if (ve[i] == 1)
            {
                ans.push_back({i, n});
                continue;
            }
            int last = i;
            for (; node.size() && ve[i] > 1; ve[i]--)
            {

                ans.push_back({last, node.front()});
                last = node.front();
                node.pop();
            }
            ans.push_back({last, n});
            // node.push(i);
        }
    }

    cout << "YES" << endl;
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
