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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

double rand_real(double a, double b)
{
    uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}

void solve()
{
    int n;
    cin >> n;
    vvt a(n,vt(3));
    int mnx = INT_MAX / 2,mxx = INT_MIN / 2,mny = INT_MAX / 2,mxy = INT_MIN / 2;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int x = a[i][0],y = a[i][1],r = a[i][2];
        mnx = min(mnx,x - r);
        mny = min(mny,y - r);
        mxx = max(mxx,x + r);
        mxy = max(mxy,y + r);
    }
    int all = 30000000;
    int cnt = 0;
    for (int i = 0;i < all;i++)
    {
        double x = rand_real(1.0 * mnx,1.0 * mxx);
        double y = rand_real(1.0 * mny,1.0 * mxy);
        for (int j = 0;j < n;j++)
        {
            double x1 = a[j][0],y1 = a[j][1],r = a[j][2];
            double d = (x - x1) * (x - x1) + (y - y1) * (y - y1);
            if (d <= r * r) 
            {
                cnt++;
                break;
            }
        }
    }
    double s = (mxx - mnx) * (mxy - mny);
    cout << fixed << setprecision(20);
    cout << 1.0 * s * cnt / all;
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
