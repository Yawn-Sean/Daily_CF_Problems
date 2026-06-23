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
    ll n,k;
    cin >> k >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll b(n);
    ll l = 0,r = LLONG_MAX / 2;
    auto check = [&](ll m) 
    {
        ll sum = 0;
        for (ll x : a) 
        {
            sum += min(x,m);
        }
        return sum <= k;
    };  
    while (l + 1 < r) 
    {
        ll m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    ll sum = 0;
    for (ll x : a) 
    {
        sum += min(x,l);
    }
    ll d = k - sum;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] > l && d > 0) 
        {
            b[i] = l + 1;
            d--;
        }
        else b[i] = min(a[i],l);
    }
    for (ll x : b) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}
