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
    double a,b,c;
    cin >> a >> b >> c;
    double x,y,z;
    cin >> x >> y >> z;
    double R;
    cin >> R;
    double mn = min({a,b,c});
    vvt d = {{-1,-1,-1},{-1,-1,1},{-1,1,-1},{-1,1,1},{1,-1,-1},{1,-1,1},{1,1,-1},{1,1,1}};
    vvd st = {{a,b,c},{a,b,0},{a,0,c},{a,0,0},{0,b,c},{0,b,0},{0,0,c},{0,0,0}};
    double ans = 0;
    for (int i = 0;i < 8;i++)
    {
        double xx = st[i][0],yy = st[i][1],zz = st[i][2];
        double l = 0,r = 2e9;
        int cnt = 100;
        while (cnt--)
        {
            double m = (l + r) / 2;
            auto check = [&](double r)
            {
                double x2 = d[i][0] * r + xx;
                double y2 = d[i][1] * r + yy;
                double z2 = d[i][2] * r + zz;
                if (r * 2 > mn) return false;
                double dis = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) + (z2 - z) * (z2 - z));
                return dis >= R + r;
            };
            if (check(m)) l = m;
            else r = m;
        }
        ans = max(ans,l);
    }
    cout << ans << endl;
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