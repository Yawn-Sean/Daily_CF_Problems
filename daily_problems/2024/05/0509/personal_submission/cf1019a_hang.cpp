#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m + 1);
    for(int i = 1; i <= n; i++){
        int p, c;
        cin >> p >> c;
        g[p].push_back(c);
    }
    for(int i = 1; i <= m; i++){
        sort(g[i].begin(), g[i].end());
    }
    auto ok = [&](int z) -> int{
        int ans = 0;
        int cnt = g[1].size();
        vector<int> c;
        for (int i = 2; i <= m; i++){
            if(g[i].size() >= z){
                int a = g[i].size() - z + 1;
                if(a >g[i].size())  return 1e15;
                cnt += a;
                for(int j=0; j < a; ++j){
                    ans += g[i][j];
                }
                for(int j = a; j < g[i].size(); ++j){
                    c.push_back(g[i][j]);
                }
            }else{
                for (int j=0; j < g[i].size(); ++j){
                    c.push_back(g[i][j]);
                }
            }
        }
        sort(c.begin(), c.end());
        for(int i=0; i < z - cnt; ++i){
            ans += c[i];
        }
        return ans;
    };
    int ans = 1e15;
    for(int i=g[1].size(); i<=n; ++i){
        ans = min(ans, ok(i));
    }
    cout << ans << endl;

}