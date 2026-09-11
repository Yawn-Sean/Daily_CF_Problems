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
    int n, k;
    cin >> n >> k;
    vpii a(n);
    vvt b(k,vt(3));
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    for (int i = 0;i < k;i++) cin >> b[i][0] >> b[i][1] >> b[i][2];
    vll dp(n + 1,LLONG_MAX / 2);
    dp[0] = 0;
    for (int i = 0;i < n;i++)
    {
        dp[i + 1] = min(dp[i + 1],dp[i] + a[i].se);
        for (int j = 0;j < k;j++)
        {
            int p = b[j][0],d = b[j][1],c = b[j][2];
            auto it = ranges::lower_bound(a,pair{a[i].fi - p + 1,-1}) - a.begin();
            if (i - d + 1 > it) it = i - d + 1;
            dp[i + 1] = min(dp[i + 1],dp[it] + c);
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}