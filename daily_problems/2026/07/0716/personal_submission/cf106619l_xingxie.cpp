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
    ll n, k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0,sum = 0;
    vt g;
    for (int x : a) 
    {
        auto it = ranges::lower_bound(g,x);
        if (it == g.end()) g.push_back(x);
        else *it = x;
        sum += x;
        ll y = g.size();
        // cout << g.back() << " " << g.size() << endl;
        if (g.back() < y) 
        {
            ans = sum + (2LL * y + k - 1) * k / 2;
        }
        else ans = sum + k * y;
        cout << ans << " ";
        // cout << sum << endl;
        // cout << g.size() << endl;
    }
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