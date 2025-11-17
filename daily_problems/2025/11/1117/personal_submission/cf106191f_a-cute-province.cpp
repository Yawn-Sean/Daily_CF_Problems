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

        }
    }
    void del(int x, int val){
        for(; x <= n; x += x&-x){
            fenwick[x]-=val;

            if(fenwick[x] <0 )fenwick[x]+=mod;
        }
    }
    int query(int l, int r){
        if(r < l)return 0;
        int suml = 0, sumr = 0;
        for(; r!=0; r -= r&-r){
            sumr += fenwick[r];
   
        }
        l--;
         for(; l!=0; l -= l&-l){
            suml += fenwick[l];
       
        }
        if(sumr - suml < 0)return sumr - suml + mod;
        return sumr - suml;
    }
};
void solve()
{   
   int n;
   cin >> n;
   vector<int> a(n+1);
   vector<PII> cnt(n+1);
   for(int i = 1; i <= n; i ++)cin >> a[i];
   int ans = 0, sum = 0;
   map<int, vector<int>> w;
   w[0].emplace_back(0);
   for(int i = 1; i <= n;i ++){
        cnt[i] = cnt[i-1];
        sum += a[i];
        if(a[i] > 0){
            cnt[i].x ++;
        }
        else cnt[i].y ++;
       w[sum].emplace_back(cnt[i].x - cnt[i].y);
   }
   map<int, BIT> mp;
   for(auto &[k, v] : w){
    sort(v.begin(), v.end());
    mp[k] = BIT(v.size());
   }
   sum = 0;
   mp[sum].add(lower_bound(w[sum].begin(), w[sum].end(), 0) - w[sum].begin() + 1, 1);
   for(int i = 1; i <= n; i ++){
        sum += a[i];
        int p = lower_bound(w[sum].begin(), w[sum].end(), cnt[i].x - cnt[i].y) - w[sum].begin() + 1;
        ans += mp[sum].query(p, w[sum].size());
        mp[sum].add(p, 1);
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
    while (t--)
    {
        solve();
    }
    return 0;
}
