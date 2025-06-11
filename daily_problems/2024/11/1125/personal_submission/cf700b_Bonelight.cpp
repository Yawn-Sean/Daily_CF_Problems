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
// #define x first
// #define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n,k; cin >> n >> k; 
    MAT g(n + 1, VC());
    VC a(n + 1);

    for(int i = 0; i < 2*k; i ++){
        int x; cin >> x; a[x] = 1;
    }

    for(int i = 0; i < n - 1; i ++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    function<int(int,int)> dfs = [&](int o, int fa){
        int cnt = a[o];
        for(auto p:g[o]) if(p != fa){
            cnt += dfs(p,o);
        }
        ans += min(2*k - cnt, cnt);
        return cnt;
    };

    dfs(1,0);
    cout << ans << endl;
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
