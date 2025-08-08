#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 1e9 + 7;
struct BIT{
    vector<int> fenwick;
    int n;
    BIT();
    BIT(int _n){
        init(_n);
        n = _n;
    }
    void init(int n){
        fenwick.resize(n+1);
    }
    void add(int x, int val){//单点查询 
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
    int query(int l, int r){//区间修改 
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
int tmp[N], arr[N];
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    BIT tree1 = BIT(n), tree2 = BIT(n);
    vector<int> l(m+1), r(m+1), c(m+1), p(m+1);
	map<int, int> id;
    vector<vector<array<int, 3>>> change(n+2);
    for(int i = 1; i <= m; i++)cin >> l[i] >> r[i] >> c[i] >> p[i];
    for (int i = 1; i <= m; ++i)  
    tmp[i] = p[i];
    std::sort(tmp + 1, tmp + m + 1);                          
    int len = std::unique(tmp + 1, tmp + m + 1) - (tmp + 1);  
    for (int i = 1; i <= m; ++i)                              
    id[p[i]] = std::lower_bound(tmp + 1, tmp + len + 1, p[i]) - tmp;
    for(int i =1 ; i<= m;i++){
        change[l[i]].push_back({id[p[i]], c[i], p[i] * c[i]}) ;
        change[r[i]+ 1].push_back({id[p[i]], -c[i], -p[i] * c[i]});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto v : change[i]){
            tree1.add(v[0], v[1]);
            tree2.add(v[0], v[2]);
        }
        
        int L = 0, R = m;
        while(L < R){
            int mid = (L + R >> 1) + 1;
            if(tree1.query(1, mid) < k)L =mid;
            else R = mid -1;
        }
        if(L == m)ans += tree2.query(1, L);
        else ans += tree2.query( 1, L) + (k - tree1.query(1, L)) * tmp[L+1];
        
    }
    cout << ans << '\n';


    
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流


     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}   
