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

const int N = 2e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    set<int> zero, one;
    int m = 0;
    vector<int> a[N];
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (zero.empty())
            {
                cout << -1 << "\n";
                return 0;
            }
            int t = *zero.begin();
            zero.erase(zero.begin());
            one.insert(t);
            a[t].pb(i + 1);
        }
        else
        {
            if (!one.empty())
            {
                int t = *one.begin();
                one.erase(one.begin());
                zero.insert(t);
                a[t].pb(i + 1);
            }
            else
            {
                zero.insert(m);
                a[m].pb(i + 1);
                ++m;
            }
        }
    }
    if (!one.empty())
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << m << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << a[i].size() << " ";
        for (int x : a[i])
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
