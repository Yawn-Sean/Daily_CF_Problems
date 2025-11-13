#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;
struct BIT{
    vector<int> fenwick;
    int n;
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
    if(!n)exit(0) ;
    BIT tr = BIT(2*n+1);
    vector<int> a(2*n+1), to(2*n+1, -1);
    vector<vector<int>> w(n+1);
    for(int i = 1; i <= 2 *n;i++)cin >> a[i], w[a[i]].emplace_back(i);
    for(int i = 1; i <= n; i++){
        int k = w[i].size()/2;
        for(int j = 0; j < k; j ++){
            to[w[i][j]] = w[i][j + k];
        }
    }   
    int ans = n *(n-1)/2;
    for(int i = 1 ; i<= 2*n; i ++){
        if(to[i] == -1)continue;
        ans -= tr.query(i, to[i]);
        tr.add(to[i], 1);
    }
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
    while (1)
    {
        solve();
    }
    return 0;
}
