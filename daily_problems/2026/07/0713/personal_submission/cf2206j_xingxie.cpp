#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,d;
    cin >> n >> d;
    vt a(n + 1),b(n + 2);
    vt pa(n + 1),pb(n + 1);
    for (int i = 1;i <= n;i++) 
    {
        cin >> a[i];
        pa[a[i]] = i;
    }
    for (int i = 1;i <= n;i++) 
    {
        cin >> b[i];
        pb[b[i]] = i;
    }
    b[n + 1] = b[n];
    int cur = 1;
    ll ans = 0;
    for (int i = 1;i <= n;i++) 
    {
        int x = b[i];
        int dd = pa[x] - cur;
        cur = pa[x] + 1;
        if (cur == n + 1) cur = 1;
        if (dd < 0) dd += n;
        ans += dd;
    }
    cout << ans << endl;
    for (int day = 1;day < d;day++)
    {
        int op,x,y;
        cin >> op >> x >> y;
        if (op == 1) 
        {
            int i1 = pb[a[x]],i2 = pb[a[y]];
            if (i1 < i2) 
            {
                int d1 = pa[b[i1]] - pa[b[i1 - 1]];
                if (d1 < 0) d1 += n;
                if (i1 == 1) 
                {
                    d1 = pa[b[i1]] - 1;
                }
                ans -= d1;
                d1 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d1 < 0) d1 += n;
                ans -= d1;
                int d2 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d2 < 0) d2 += n;
                ans -= d2; 
                if (i1 + 1 != i2)
                {
                    int d2 = pa[b[i2]] - pa[b[i2 - 1]];
                    if (d2 < 0) d2 += n;
                    ans -= d2;
                }
            }
            else 
            {
                int d1 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d1 < 0) d1 += n;
                ans -= d1;
                d1 = pa[b[i2]] - pa[b[i2 - 1]];
                if (d1 < 0) d1 += n;
                if (i2 == 1) 
                {
                    d1 = pa[b[i2]] - 1;
                }
                ans -= d1;
                int d2 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d2 < 0) d2 += n;
                ans -= d2; 
                if (i2 + 1 != i1)
                {
                    int d2 = pa[b[i1]] - pa[b[i1 - 1]];
                    if (d2 < 0) d2 += n;
                    ans -= d2;
                }
            }

            if (i1 == n) 
            {
                b[n + 1] = b[i2];
            }
            if (i2 == n) 
            {
                b[n + 1] = b[i1];
            }
            pb[a[x]] = i2;
            pb[a[y]] = i1;
            swap(b[i1],b[i2]);

            if (i1 < i2) 
            {
                int d1 = pa[b[i1]] - pa[b[i1 - 1]];
                if (d1 < 0) d1 += n;
                if (i1 == 1) 
                {
                    d1 = pa[b[i1]] - 1;
                }
                ans += d1;
                d1 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d1 < 0) d1 += n;
                ans += d1;
                int d2 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d2 < 0) d2 += n;
                ans += d2; 
                if (i1 + 1 != i2)
                {
                    int d2 = pa[b[i2]] - pa[b[i2 - 1]];
                    if (d2 < 0) d2 += n;
                    ans += d2;
                }
            }
            else 
            {
                int d1 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d1 < 0) d1 += n;
                ans += d1;
                d1 = pa[b[i2]] - pa[b[i2 - 1]];
                if (d1 < 0) d1 += n;
                if (i2 == 1) 
                {
                    d1 = pa[b[i2]] - 1;
                }
                ans += d1;
                int d2 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d2 < 0) d2 += n;
                ans += d2; 
                if (i2 + 1 != i1)
                {
                    int d2 = pa[b[i1]] - pa[b[i1 - 1]];
                    if (d2 < 0) d2 += n;
                    ans += d2;
                }
            }
        }
        else 
        {
            int i1 = x,i2 = y;
            if (i1 < i2) 
            {
                int d1 = pa[b[i1]] - pa[b[i1 - 1]];
                if (d1 < 0) d1 += n;
                if (i1 == 1) 
                {
                    d1 = pa[b[i1]] - 1;
                }
                ans -= d1;
                d1 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d1 < 0) d1 += n;
                ans -= d1;
                int d2 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d2 < 0) d2 += n;
                ans -= d2; 
                if (i1 + 1 != i2)
                {
                    int d2 = pa[b[i2]] - pa[b[i2 - 1]];
                    if (d2 < 0) d2 += n;
                    ans -= d2;
                }
            }
            else 
            {
                int d1 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d1 < 0) d1 += n;
                ans -= d1;
                d1 = pa[b[i2]] - pa[b[i2 - 1]];
                if (d1 < 0) d1 += n;
                if (i2 == 1) 
                {
                    d1 = pa[b[i2]] - 1;
                }
                ans -= d1;
                int d2 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d2 < 0) d2 += n;
                ans -= d2; 
                if (i2 + 1 != i1)
                {
                    int d2 = pa[b[i1]] - pa[b[i1 - 1]];
                    if (d2 < 0) d2 += n;
                    ans -= d2;
                }
            }

            if (i1 == n) 
            {
                b[n + 1] = b[i2];
            }
            if (i2 == n) 
            {
                b[n + 1] = b[i1];
            }
            pb[b[x]] = i2;
            pb[b[y]] = i1;
            swap(b[i1],b[i2]);

            if (i1 < i2) 
            {
                int d1 = pa[b[i1]] - pa[b[i1 - 1]];
                if (d1 < 0) d1 += n;
                if (i1 == 1) 
                {
                    d1 = pa[b[i1]] - 1;
                }
                ans += d1;
                d1 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d1 < 0) d1 += n;
                ans += d1;
                int d2 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d2 < 0) d2 += n;
                ans += d2; 
                if (i1 + 1 != i2)
                {
                    int d2 = pa[b[i2]] - pa[b[i2 - 1]];
                    if (d2 < 0) d2 += n;
                    ans += d2;
                }
            }
            else 
            {
                int d1 = pa[b[i1 + 1]] - pa[b[i1]];
                if (d1 < 0) d1 += n;
                if (i2 == 1) 
                {
                    d1 = pa[b[i2]] - 1;
                }
                ans += d1;
                d1 = pa[b[i2]] - pa[b[i2 - 1]];
                if (d1 < 0) d1 += n;
                if (i2 == 1) 
                {
                    d1 = pa[b[i2]] - 1;
                }
                ans += d1;
                int d2 = pa[b[i2 + 1]] - pa[b[i2]];
                if (d2 < 0) d2 += n;
                ans += d2; 
                if (i2 + 1 != i1)
                {
                    int d2 = pa[b[i1]] - pa[b[i1 - 1]];
                    if (d2 < 0) d2 += n;
                    ans += d2;
                }
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}