/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define MAT vector<VC>
#define x first
#define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    struct Subj
    {
        int l,r,c,id;
    };
    
    int n,m,k; cin >> n >> m >> k;
    vector<Subj> a(m);
    for(int i = 0; i < m; i ++) {
        auto &[l,r,c,id] = a[i];
        cin >> l >> r >> c;
        id = i;
    }

    sort(begin(a), end(a), [&](auto x, auto y){
        return x.c < y.c;
    });

    vector<MAT> dp(m, MAT(n, VC(105)));
    vector<vector<vector<pii>>> pre(m, vector<vector<pii>>(n, vector<pii>(105)));

    for(int i = 0; i < m; i ++)
    for(int j = 0; j < n; j ++)
    for(int u = a[i].l; u <= a[i].r; u ++){
        int t = u - a[i].l;
        if(j == 0) {dp[i][j][t] = u; continue;}
        
        for(int v = 0; v < i; v ++){
            if(a[i].c == a[v].c) continue;
            if(u - k >= a[v].l && u - k <= a[v].r 
                && dp[v][j-1][u - a[v].l - k] && dp[v][j-1][u - a[v].l - k] + u > dp[i][j][t])
            {
                dp[i][j][t] = dp[v][j-1][u - a[v].l - k] + u;
                pre[i][j][t] = {v,u - a[v].l - k};
            }
            if(u % k == 0 && u/k >= a[v].l && u/k <= a[v].r
                && dp[v][j - 1][u/k - a[v].l] && dp[v][j - 1][u/k - a[v].l] + u > dp[i][j][t])
            {   
                dp[i][j][t] = dp[v][j-1][u/k - a[v].l] + u;
                pre[i][j][t] = {v, u/k - a[v].l};
            }
        }
    }

    int ans = -INF, STidx, STval; 
    for(int i = 0; i < m; i ++)
    for(int j = a[i].l; j <= a[i].r; j ++){
        int t = j - a[i].l;
        if(dp[i][n-1][t] && dp[i][n-1][t] > ans) ans = dp[i][n-1][t], STidx = i, STval = t;
    }

    if(ans == -INF) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector<pii> ans;
        ans.push_back({STidx,STval+a[STidx].l});

        int ed = n-1;
        while(ed > 0){
            auto [id,v] = pre[STidx][ed][STval];
            ans.push_back({id, v+a[id].l});
            ed --;
            STidx = id, STval = v;
        }
        reverse(begin(ans), end(ans));
        for(auto [x,y]:ans) cout << a[x].id+1 << ' ' << y << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
