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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt dis(n,INT_MAX / 2);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : g[x])
        {
            if (dis[y] == INT_MAX / 2) 
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    if (dis[1] == INT_MAX / 2)
    {
        cout << 0 << endl;
        return ;
    }
    int day = (dis[1] + k - 1) / k;
    int maxlen = day * k;
    vll cur(n),nxt(n),cnt(maxlen + 1);//当前走len - 1条边 ,停在x的方案数  再走一条边,停在y的方案数  恰好走len条边 从1到2的方案数
    cur[0] = 1;
    for (int len = 1;len <= maxlen;len++)
    {
        fill(nxt.begin(),nxt.end(),0);
        for (int x = 0;x < n;x++) 
        {
            if (cur[x] == 0) continue;
            for (int y : g[x])
            {
                nxt[y] = (nxt[y] + cur[x]) % MOD;
            }
        }
        cur = nxt;
        cnt[len] = cur[1];
    }
    vll dp(maxlen + 1);//总共走len条边,每天走1到k条边 的方案数
    dp[0] = 1;
    for (int d = 1;d <= day;d++)
    {
        vll ndp(maxlen + 1);
        for (int len = 1;len <= maxlen;len++)
        {
            for (int x = 1;x <= min(k,len);x++)
            {
                ndp[len] += dp[len - x];
                ndp[len] %= MOD;
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int len = dis[1];len <= maxlen;len++)
    {
        ans = (ans + cnt[len] * dp[len]) % MOD;
    }
    cout << ans << endl;
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