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
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    ll cnt1 = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        for (char c : a[i]) cnt1 += (c == '1');
    }
    vvt l(n + 1,vt(m + 1)),r(n + 1,vt(m + 1)),u(n + 1,vt(m + 1)),d(n + 1,vt(m + 1));
    vt col(m),row(n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) l[i][j + 1] = l[i][j] + (a[i][j] == '1');
        for (int j = m - 1;j >= 0;j--) r[i][j] = r[i][j + 1] + (a[i][j] == '1');
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '0') continue;
            row[i] += u[i][j] + d[i + 1][j];
        }
    }
    for (int j = 0;j < m;j++)
    {
        for (int i = 0;i < n;i++) u[i + 1][j] = u[i][j] + (a[i][j] == '1');
        for (int i = n - 1;i >= 0;i--) d[i][j] = d[i + 1][j] + (a[i][j] == '1');
        for (int i = 0;i < n;i++) 
        {
            if (a[i][j] == '0') continue;
            col[j] += l[i][j] + r[i][j + 1];
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '0') continue;
            row[i] += u[i][j] + d[i + 1][j];
        }
    }
    int mx = 0,ans = 0;
    ll sum = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            ll LL = l[i][j],rr = r[i][j + 1];
            ll uu = u[i][j],dd = d[i + 1][j];
            if (a[i][j] == '1') 
            {
                sum += (LL + rr) * (uu + dd);
                continue;
            }
            ll ds = (LL + rr) * (uu + dd) + col[j] + row[i];
            if (ds > mx) 
            {
                mx = ds;
                ans = 1;
            }
            else if (ds == mx) ans++;
        }
    }
    cout << mx + sum << " " << ans << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}