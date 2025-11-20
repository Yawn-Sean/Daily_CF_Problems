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
struct node{
    int max_idx;
    int nex[2];
}tr[N*30];
int len;
    void insert(int s, int v){
        int p = 0;
        for(int i = 30; i >= 0; i --){
            
            int w = ((s >> i) & 1);
            if(tr[p].nex[w] == 0){
                tr[p].nex[w] = ++ len;
            }
            p = tr[p].nex[w];
            tr[p].max_idx = max(v, tr[p].max_idx);
        }
        return ;
    }
    int query(int a, int v){
        int p = 0;
        int res = 0;
        for(int i = 30; i >= 0; i --){
            int ai = ((a >> i) & 1);
            int vi = ((v >> i) & 1);
            if(vi == 1){
                if(tr[p].nex[0^ai] != 0){
                    res = max(res, tr[tr[p].nex[0^ai]].max_idx);
                }
                if(tr[p].nex[1 ^ ai] != 0){
                    p = tr[p].nex[1 ^ ai];
                }
                else return res;
            }
            else{
                if(tr[p].nex[0^ai] != 0){
                    p = tr[p].nex[0^ai];
                }
                else return res;
            }
        }
        return res;
    }
    


void solve()
{   
   int n, k;
   cin >> n >> k;
   vector<int> a(n+1);
   for(int i = 1; i <= n; i ++)cin >> a[i];
   int ans1 = 0, ans2 = 0, p1 = 0, p2 = 0;
    for(int r = 1; r <= n; r ++){
        int l1 = query(a[r], k);
        int l2 = query(a[r], k+1);
        p1 = max(p1, l1);
        p2 = max(p2, l2);
        ans1 += r-1-p1;
        ans2 += r-1-p2;
        //cout << p1 << ' ' <<p2 << '\n';
        //cout << ans1 <<' ' << ans2 << '\n';  
        insert(a[r], r);
    }
    cout << ans1 - ans2 << '\n';
    
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
