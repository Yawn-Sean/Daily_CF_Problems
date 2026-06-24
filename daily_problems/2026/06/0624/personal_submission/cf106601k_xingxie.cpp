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
    int n,q;
    cin >> n >> q;
    vt a(n),cnt(1e6 + 1);
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        a[i] = x;
        cnt[x]++;
    }
    vt p(1e6 + 1);
    for (int i = 1;i <= 1e6;i++) 
    {
        if (cnt[i] > 0) 
        {
            p[cnt[i]]++;
        }
    }
    vt ans(1e6 + 1);
    for (int i = 1;i <= 1e6;i++) 
    {
        for (int j = i;j <= 1e6;j += i) 
        {
            ans[i] += p[j];
        }
    }
    // cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << endl;
    while (q--) 
    {
        int op;
        cin >> op;
        if (op == 2) 
        {
            int x;
            cin >> x;
            cout << ans[x] << endl;
        }
        else 
        {
            int i,x;
            cin >> i >> x;
            i--;
            int y = a[i];
            a[i] = x;
            auto del = [&](int x) -> void
            {
                for (int i = 1;1LL * i * i <= cnt[x];i++) 
                {
                    if (cnt[x] % i == 0) 
                    {
                        ans[i]--;
                        if (cnt[x] / i != i) ans[cnt[x] / i]--;
                    }
                }
            };
            auto add = [&](int x) -> void
            {
                for (int i = 1;1LL * i * i <= cnt[x];i++) 
                {
                    if (cnt[x] % i == 0) 
                    {
                        ans[i]++;
                        if (cnt[x] / i != i) ans[cnt[x] / i]++;
                    }
                }
            };
            del(y);
            // cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << endl;
            cnt[y]--;
            add(y);
            // cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << endl;
            del(x);
            // cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << endl;
            cnt[x]++;
            add(x);
            // cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << endl;
        }
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