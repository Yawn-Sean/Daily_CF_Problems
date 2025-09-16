#include <bits/stdc++.h>

#define int long long
#define ld long double
#define ll long long
#define lowbit(x) x & -x
using namespace std;

const int N = 6000;
const int mod = 998244353;
const int INF = 1e18;

#define endl '\n'
#define rep(l, r) for (int i = l; i <= r; i++)
#define lep(r, l) for (int i = r; i >= l; i--)

using pii = pair<int, int>;
using i64 = int64_t;


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(1, n) cin >> a[i];
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 2)
        {
            int y;
            cin >> y;
            if (n >= 2000)// 1e3*1e3*1e3=1e9>=a[i]max
            { 
                if (2000 - y >= 1000)
                    cout << 2000 << endl;
                else
                    cout << 1 << endl;
            }
            else
            {
                int fl = 0;
                for (int l = y; l >= 1; l--)
                {
                    if (l >= 1 && (y - l) * (y - l) * (y - l) >= a[l])
                    {
                        cout << l << endl;
                        fl = 1;
                        break;
                    }
                }
                for (int r = y + 1; r <= n; r++)
                {
                    if (fl)
                        break;
                    if (r <= n && (r - y) * (r - y) * (r - y) >= a[r])
                    {
                        cout << r << endl;
                        fl = 1;
                        break;
                    }
                }
                if(fl==0)cout<<-1<<endl;
            }
        }
        else if (x == 1)
        {
            int y, z;
            cin >> y >> z;
            a[y] = z;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
