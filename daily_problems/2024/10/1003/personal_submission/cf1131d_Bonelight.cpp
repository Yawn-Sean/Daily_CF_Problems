/*
    Bonelight * V *
    20241003: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n,m; cin >> n >> m;
    vector<int> X(n + m);
    iota(begin(X),end(X),0);
    
    vector<string> tab(n);
    for(int i = 0; i < n; i ++) cin >> tab[i];
#pragma region 
    function<int(int)> find = [&](int o){return X[o] = X[o] == o? o : find(X[o]);};
    auto merge = [&](int xx, int yy){
        int x = find(xx), y = find(yy);
        if(x == y) return;
        X[x] = y;
    };
#pragma endregion

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(tab[i][j] == '=') merge(i,n + j);
        }
    }

    vector<int> du(n + m);
    vector<vector<int>> g(n + m, vector<int>());
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int x = find(i), y = find(n + j);
            if(tab[i][j] == '>')  du[x] ++, g[y].push_back(x);
            if(tab[i][j] == '<')  du[y] ++, g[x].push_back(y);
        }
    }
    
    int cnt = 0;
    queue<int> qu;
    vector<int> ans(n + m);
    for(int i = 0; i < n + m; i ++){
        if(du[i] == 0){
            qu.push(i);
            ans[i] = 1;
        }
    }

    while(qu.size()){
        int o = qu.front(); qu.pop();
        cnt ++;
        for(auto p:g[o]){
            ans[p] = max(ans[p], ans[o] + 1);
            du[p]--;
            if(du[p] == 0){
                qu.push(p);
            }
        }
    }

    if(cnt < n + m){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i ++) cout << ans[find(i)] << ' ';
        cout << endl;
        for(int i = 0; i < m; i ++) cout << ans[find(n + i)] << ' ';
        cout << endl;
    }
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
