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
// #define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string ans(n,' ');
    auto ask = [&](vt& a)
    {
        cout << "? " << a.size() << " ";
        for (int x : a) cout << x << " ";
        cout << endl;
        int r;
        cin >> r;
        return r;
    };
    vt a = {1,2};
    int r = ask(a);
    if (r == 0) 
    {
        int j = -1;
        for (int i = 3;i <= n;i++)
        {
            a.push_back(i);
            int rr = ask(a);
            if (rr) 
            {
                ans[i - 1] = 'T';
                j = i - 1;
                a.pop_back();
            }
        }
        a = {j + 1};
        for (int i = 1;i <= n;i++)
        {
            if (ans[i - 1] == 'T') continue;
            a.push_back(i);
            int rr = ask(a);
            if (rr == 1) ans[i - 1] = 'F';
            else ans[i - 1] = 'M';
            a.pop_back();
        }
    }
    else 
    {
        int f = 1;
        a.pop_back();
        vt cnt(n);
        for (int i = 3;i <= n;i++)
        {
            a.push_back(i);
            int rr = ask(a);
            cnt[i - 1] = rr;
            if (!rr) f = 0;
            a.pop_back();
        }
        if (f) 
        {
            ans[0] = 'T';
            int j = -1;
            if (r == 1) 
            {
                ans[1] = 'F';
                j = 2;
            }
            for (int i = 3;i <= n;i++)
            {
                if (cnt[i - 1] == 1) 
                {
                    ans[i - 1] = 'F';
                    j = i;
                }
            }
            a = {j};
            for (int i = 1;i <= n;i++)
            {
                if (ans[i - 1] == 'F') continue;
                a.push_back(i);
                int rr = ask(a);
                if (rr == 0) ans[i - 1] = 'M';
                else ans[i - 1] = 'T';
                a.pop_back();
            }
        }
        else 
        {
            ans[1] = 'T';
            for (int i = 3;i <= n;i++)
            {
                if (cnt[i - 1]) ans[i - 1] = 'T';
            }
            a = {2};
            for (int i = 1;i <= n;i++)
            {
                if (ans[i - 1] == 'T') continue;
                a.push_back(i);
                int rr = ask(a);
                if (rr == 1) ans[i - 1] = 'F';
                else ans[i - 1] = 'M';
                a.pop_back();
            }
        }
    }
    cout << "! " << ans << endl;
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