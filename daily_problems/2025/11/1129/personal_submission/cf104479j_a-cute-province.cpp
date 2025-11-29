#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 5e5 + 10;
struct BIT{
    vector<int> fenwick;
    int n;
    BIT() : n(0) {} 
    BIT(int _n){
        init(_n);
        n = _n;
    }
    void init(int n){
        fenwick.resize(n+1);
    }
    void add(int x, int val){
        for(; x <= n; x += x&-x){
            fenwick[x]+=val;
            fenwick[x] %= mod;
        }
    }
    void del(int x, int val){
        for(; x <= n; x += x&-x){
            fenwick[x]-=val;
            fenwick[x] %= mod;
            if(fenwick[x] <0 )fenwick[x]+=mod;
        }
    }
    int query(int l, int r){
        if(r < l)return 0;
        int suml = 0, sumr = 0;
        for(; r!=0; r -= r&-r){
            sumr += fenwick[r];
            sumr %= mod;
        }
        l--;
         for(; l!=0; l -= l&-l){
            suml += fenwick[l];
            suml%=mod;
        }
        if(sumr - suml < 0)return sumr - suml + mod;
        return sumr - suml;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> s(n+1);
    vector<int> k(n+1), arr;
    vector<PII> p;
    for(int i = 1; i <=n; i ++){
        cin >> k[i];
        s[i].resize(k[i]);
        for(int j = 0; j < k[i] ;j ++){
            cin >> s[i][j];
            arr.emplace_back(s[i][j]);
        }
        sort(s[i].begin(), s[i].end());
        
    }   
    std::vector<int> tmp(arr);  
        std::sort(tmp.begin(), tmp.end());
        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
        for(int i = 1; i <= n; i ++)
        for (int j = 0; j < k[i]; ++j)
        s[i][j] = std::lower_bound(tmp.begin(), tmp.end(), s[i][j]) - tmp.begin() + 1;
        set<PII> have;
    for(int i = 1; i <= n; i ++){
        auto w = have.upper_bound({s[i][0], i});
        if(w == have.end())p.emplace_back(s[i][k[i]-1], i);
        else{
            int j = 0;
            while(j < k[i] && make_pair(s[i][j], i) < (*w))j ++;
            j--;
            p.emplace_back(s[i][j], i);
        }
        have.insert(make_pair(p.back().x, i));
    }
    sort(p.begin(), p.end());

    vector<PII> dp, ndp;
    BIT bit = BIT(N);
    for(auto i : s[p[0].y]){
        dp.emplace_back(i, 1);
    }
    for(int i = 1; i < n; i ++){    
        ndp.clear();
        for(auto [i, v] : dp){
            bit.add(i, v);
        }
        int pre = p[i-1].y, cur = p[i].y;
        for(auto u : s[cur]){
            int sum = 0;
            if(pre < cur){
                sum += bit.query(1,u);
            }
            else sum += bit.query(1,u-1);
            ndp.emplace_back(u, sum);
        }
        for(auto [i, v] : dp){
            bit.add(i, -v);
        }
        dp = ndp;
    }
    int ans = 0;
    for(auto [_, val] : dp)ans = (ans + val)%mod;
    cout << ans << '\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
