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
const int N = 2000 + 10;
struct BIT{
    vector<int> fenwick;
    int n;
    BIT(int _n){
        n = _n;
        fenwick.assign(n+1, 0);
    }
    void add(int x, int val){
        for(; x <= n; x += x&-x){
            fenwick[x]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(; x > 0; x -= x&-x) sum += fenwick[x];
        return sum;
    }
    int query(int l, int r){
        if(r < l) return 0;
        return query(r) - query(l-1);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), next(n+1), pre(n+1);
    vector<vector<int>> event(n+2);
    map<int, vector<int>> w;
    BIT bit = BIT(n);
    for(int i =1; i <= n; i ++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i], w[b[i]].emplace_back(i);
    for(int i = 1; i <= n; i++){
        if(w.find(a[i]) == w.end())next[i] = n+1;
        else{
            auto p = lower_bound(w[a[i]].begin(), w[a[i]].end(), i);
            if(p == w[a[i]].end())next[i] = n+1;
            else next[i] = *p;
        }
        event[next[i]].emplace_back(i);
        if(w.find(a[i]) == w.end())pre[i] = 0;
        else{
            auto p = upper_bound(w[a[i]].begin(), w[a[i]].end(), i);
            if(p == w[a[i]].begin())pre[i] = 0;
            else pre[i] = *(p-1);
        }
        
    }
    int ans = 0;
    for(int r = 1; r <= n; r ++){
        for(auto l : event[r]){
            bit.add(l, 1);
        }
        ans += bit.query(pre[r]+1, r-1);
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
