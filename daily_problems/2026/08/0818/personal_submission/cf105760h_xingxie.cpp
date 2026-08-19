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
    int k,s,e;
    cin >> k >> s >> e;
    vt a = {s};
    for (int i = 1;i <= k;i++)
    {
        if (i != s && i != e) a.push_back(i);
    }
    a.push_back(e);
    vvt ans;
    int l = 1,r = k;
    for (int m = k - 1;m >= 1;m--)
    {
        for (int d = 1;d <= m;d++)
        {
            ans.push_back({a[0],a[r - d]});
        }
        for (int d = m - 1;d >= 1;d--)
        {
            ans.push_back({a[r - d],a[l]});
        }
        l++;
    }
    for (int m = 2;m < k;m++)
    {
        ans.push_back({a[r - m],a[0]});
        for (int i = 1;i < m;i++)
        {
            ans.push_back({a[r - m],a[r - m + i]});
        }
        for (int i = 2;i < m;i++)
        {
            ans.push_back({a[r - i],a[r - 1]});
        }
        ans.push_back({a[0],a[r - 1]});
    }
    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
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