/*
    Bonelight * v *
    20241028：58要早八
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(2, vector<int>(n + 1));

    for(int i = 1; i <= n; i ++ ) cin >> g[0][i];
    for(int i = 1; i <= n; i ++ ) cin >> g[1][i];

    vector<int> s1(n + 2), s2(n + 2), s3(n + 2);
    for(int i = n; i >= 0; i --){
        s1[i] = s1[i + 1] + g[0][i] + g[1][i]; // 后缀和a，b
        s2[i] = s2[i + 1] + s1[i + 1] + g[1][i] + (g[1][i] * (n - i)*2); // 上右回
        s3[i] = s3[i + 1] + s1[i + 1] + g[1][i] + (g[0][i + 1] * (n - i)*2); // 下右回
    }

    vector<vector<int>> s4(2, vector<int>(n + 1));
    vector<array<int,2>> df = {{1,0},{0,1},{-1,0},{0,1}};
    int x = 0, y = 1;
    
    int lx = 0, ly = 0;
    for(int i = 0; i < n*2; i ++) {
        s4[x][y] = s4[lx][ly] + i * g[x][y];
        lx = x, ly = y;
        x += df[i % 4][0], y += df[i % 4][1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        ans = max(ans,s4[0][i - 1] + s2[i] + s1[i] * (i - 1) * 2);
        ans = max(ans,s4[0][i - 1] + s3[i] + s1[i] * (i - 1) * 2);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
