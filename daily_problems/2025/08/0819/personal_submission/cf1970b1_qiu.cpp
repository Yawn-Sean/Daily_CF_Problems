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
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cout << i << ' ' << i << endl;
        if (i > a / 2)
            ans.push_back(i - a / 2);
        else
            ans.push_back(i + a / 2);
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
