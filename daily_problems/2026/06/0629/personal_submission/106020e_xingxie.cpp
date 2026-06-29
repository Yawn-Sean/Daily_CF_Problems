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
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vt vis(n + 1);
    vll o;
    ll ans = 0;
    for (int i = 1;i <= n;i++)
    {
        int x = a[i];
        if (vis[x]) continue;
        int cnt = 0;
        ll s = 0;
        int last = x;
        vt b;
        while (!vis[x]) 
        {
            vis[x] = 1;
            b.push_back(x);
            if (cnt % 2 == 0) s += x;
            else s -= x;
            x = a[x];
            cnt++;
        }
        if (cnt % 2 == 0) 
        {
            ans += abs(s);
        }
        else 
        {
            ll cur = s;
            for (int i = 0;i < b.size();i++) 
            {
                cur = 2 * b[i] - cur;
                s = max(s,cur);
            }
            o.push_back(s);
        }
    }
    ranges::sort(o,{},[&](auto& a) {return -a;});
    for (int i = 0;i < o.size();i++)
    {
        if (i % 2 == 0) ans += o[i];
        else ans -= o[i];
        // cout << o[i] << endl;
    }
    cout << ans << endl;
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