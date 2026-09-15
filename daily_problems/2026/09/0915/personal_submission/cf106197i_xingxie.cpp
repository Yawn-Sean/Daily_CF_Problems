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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt r(n),c(n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (a[i][j] == 'H') r[i] = 1;
            else c[j] = 1;
        }
    }
    cout << n << endl;
    int f = 1;
    for (int x : r)
    {
        if (!x) f = 0;
    }
    if (f) 
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (a[i][j] == 'H') 
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    break;
                }
            }
        }
    }
    else 
    {
        for (int j = 0;j < n;j++)
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i][j] == 'V') 
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    break;
                }
            }
        }
    }
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