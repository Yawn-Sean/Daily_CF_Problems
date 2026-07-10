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
    vvt a(n),b(n);
    map<int,int> c1,c2;
    for (int i = 0;i < n;i++) 
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0;j < k;j++) 
        {
            cin >> a[i][j];
            c1[a[i][j]]++;
        }
    }
    for (int i = 0;i < n;i++) 
    {
        int k;
        cin >> k;
        b[i].resize(k);
        for (int j = 0;j < k;j++) 
        {
            cin >> b[i][j];
            c2[b[i][j]]++;
        }
    }
    if (a == b) 
    {
        cout << "S" << endl;
        return ;
    }
    if (c1 != c2) 
    {
        cout << "N" << endl;
        return ;
    }
    if (n >= 3) 
    {
        cout << "S" << endl;
    }
    else if (n == 2) 
    {
        int mn = INT_MAX / 2;
        if (!a[0].empty()) mn = min(mn,a[0].back());
        if (!a[1].empty()) mn = min(mn,a[1].back());
        if (!b[0].empty()) mn = min(mn,b[0].back());
        if (!b[1].empty()) mn = min(mn,b[1].back());
        for (int i = 0;i < n;i++) 
        {
            while (a[i].size() && a[i].back() == mn) a[i].pop_back();
            while (b[i].size() && b[i].back() == mn) b[i].pop_back();
        }
        if (a == b) cout << "S" << endl;
        else cout << "N" << endl;
    }
    
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