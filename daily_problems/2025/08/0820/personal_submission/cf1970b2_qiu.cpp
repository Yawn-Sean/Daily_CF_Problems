#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    int a;
    cin >> a;
    cout << "YES" << endl;
    ans.push_back(1);
    vector<int> x(n + 1, 1), y(n + 1, 1);
    x[1] = 1;
    y[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        if (a < i)
        {
            x[i] = x[i - a];
            y[i] = i;
            ans.push_back(i - a);
        }
        else
        {
            y[i] = i;
            x[i] = x[1] + a - i + 1;
            ans.push_back(1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << y[i] << ' ' << x[i] << endl;
    }
    for (auto v : ans)
    {
        cout << v << ' ';
    }
    cout << endl;
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
