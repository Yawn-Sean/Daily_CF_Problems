#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e2; 
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
void solve()
{
    int n;
    cin >> n;
    vector<int>  r(n+1), ans(n+1);
    for(int i =1; i <= n;i++)cin >> r[i]; 
    BIT tree = BIT(2*n+1);
    for(int i = 1; i <= n; i++){
        if(r[i] >= i)tree.add(r[i]+n, 1);
    }

    for(int i = n;i >=1 ; i--){
        int v = (r[i] >=i ? r[i] : r[i]+n);
        ans[r[i]] = v -i -tree.query(1, v);
        tree.add(v, 1);
    }
    for(int i = 1; i <= n;i ++)
    cout << ans[i] << ' ';
    cout << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
