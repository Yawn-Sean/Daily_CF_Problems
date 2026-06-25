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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt p;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] > 0) p.push_back(i);
    }
    int m = p.size();
    ll ans = 0;
    for (int i = 0;i + 1 < m;i++)
    {
        int x = a[p[i]],y = a[p[i + 1]];
        if ((x == 1 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 1)) 
        {
            int f0 = (p[i + 1] - p[i]) > 1;
            int L = 0,R = 0;
            if (i - 1 >= 0) L = p[i] - p[i - 1] - 1;
            else L = p[i];
            if (i + 2 < m) R = p[i + 2] - p[i + 1] - 1;
            else R = n - p[i + 1] - 1;
            ll d = 1LL * (L + 1) * (R + 1);
            ans += d - !f0;
        }
    }
    cout << ans << endl;
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