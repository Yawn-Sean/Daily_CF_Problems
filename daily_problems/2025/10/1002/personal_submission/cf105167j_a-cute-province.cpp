#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
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

        }
    }
    void del(int x, int val){
        for(; x <= n; x += x&-x){
            fenwick[x]-=val;


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
        if(sumr - suml < 0)return sumr - suml;
        return sumr - suml;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> id(n+1), a(n+1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int ans = n * n;
    int tp1 = 3, tp2 = 2; 
    for(int i = 1; i <= n; i ++){
        if(a[i] == n/2 + 1)id[a[i]] = n;
        else if(a[i] == n/2)id[a[i]] = 1;
        else if(a[i] < n/2)id[a[i]] = tp1, tp1+=2;
        else id[a[i]] = tp2, tp2 += 2;
    }
    auto calc = [&]()->int{
        BIT bit = BIT(n+1);
        int res = 0;
        for(int i =1 ; i<= n; i++){
            res += bit.query(id[a[i]]+1, n);
            bit.add(id[a[i]], 1);
        }
        return res;
    };
    ans = min(ans, calc());
    tp1 = 3, tp2 = 2;
    for(int i = 1; i <= n; i ++){
        if(a[i] == n/2 + 1)id[a[i]] = 1;
        else if(a[i] == n/2)id[a[i]] = n;
        else if(a[i] < n/2)id[a[i]] = tp2, tp2+=2;
        else id[a[i]] = tp1, tp1 += 2;
    }
    ans = min(ans, calc());
    cout << n * n/2 -1 <<' ' << ans << '\n';
}

signed cute_prov0nce()
{
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
