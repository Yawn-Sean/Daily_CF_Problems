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
    int n;
    cin >> n;
    vt r(n),c(n);
    for (int i = 0;i < n;i++) cin >> r[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    ll sr = accumulate(r.begin(),r.end(),0LL);
    ll sc = accumulate(c.begin(),c.end(),0LL);
    vvll dp(n + 1,vll(2,LLONG_MAX / 2));
    dp[1][0] = r[0];
    dp[1][1] = c[0];
    for (int i = 1;i < n - 1;i++)
    {
        dp[i + 1][0] = min(dp[i][0],dp[i][1] + r[i]);
        dp[i + 1][1] = min(dp[i][1],dp[i][0] + c[i]);
    }
    dp[n][0] = dp[n - 1][1] + r[n - 1];
    dp[n][1] = dp[n - 1][0] + c[n - 1];
    cout << min({dp[n][0],dp[n][1],sr,sc}) << endl;

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