#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,k; cin >> n >> k;
    vector<string> g(n);
    for(int i = 0; i < n; i ++){
        cin >> g[i];
    }

    vector<vector<int>> dp(n, vector<int> (n,n * 2));
    dp[0][0] = 0;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(i && dp[i - 1][j] < dp[i][j]) dp[i][j] = dp[i - 1][j];
            if(j && dp[i][j - 1] < dp[i][j]) dp[i][j] = dp[i][j - 1];
            dp[i][j] += g[i][j] == 'a'?  0:1;
        }
    }
    int cnt = 0;
    vector<pii> ps = {{0,0}};

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(dp[i][j] <= k){
                if(i + j > cnt){ // 更多 a
                    cnt = i + j;
                    ps.clear();
                    ps.push_back({i,j});
                } else if (i + j == cnt){ // 相同 a
                    ps.push_back({i,j});
                }
            }
        }
    }

    cout << string(cnt, 'a');

    auto [tx,ty] = ps[0];
    cout << (dp[tx][ty] <= k? 'a': g[tx][ty]);


    vector<pii> dist = {{0,1}, {1,0}};
    for(int i = cnt + 1; i < 2 * n - 1; i ++){
        char ch = 'z' + 1;
        vector<pii> nps;
        for(auto [x,y]: ps){
            for(auto [dx,dy]: dist){
                if(x + dx < n && y + dy < n){
                    int xx = x + dx, yy = y + dy;
                    if(g[xx][yy] < ch){
                        ch = g[xx][yy];
                        nps.clear();
                        nps.push_back({xx,yy});
                    } else if(g[xx][yy] == ch && nps.back().first != xx){
                        nps.push_back({xx,yy});
                   } 
                }
            }        
        }
        cout << ch;
        ps = nps;
    }

}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
