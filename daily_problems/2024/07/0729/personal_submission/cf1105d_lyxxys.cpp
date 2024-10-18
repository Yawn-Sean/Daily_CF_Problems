#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1505, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    vector <vector<int>> col(n+1, vector<int>(m+1));
    vector <int> spd(p+1), cnt(p+1);
    string g[n+1];
    for (int i = 1; i <= p; ++ i) cin >> spd[i];
    for (int i = 1; i <= n; ++ i) cin >> g[i], g[i] = " " + g[i];

    queue <array<int,2>> Q[p+1];
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (isdigit(g[i][j])){
                int x = g[i][j]-'0';
                Q[x].push({i,j});
                col[i][j] = x;
            }
        }
    }

    const int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    bool flg = 1;
    while (flg){
        flg = 0;
        for (int i = 1; i <= p; ++ i){
            if (!Q[i].empty()){
                // 至少有一个扩展则这轮合法
                flg = 1;
                int sum = spd[i];
                // 每轮扩展spd[i]次
                while (sum--){
                    queue <array<int,2>> qs;
                    bool brake = 1;
                    while (!Q[i].empty()){
                        auto u = Q[i].front();
                        Q[i].pop();
                        for (int j = 0; j < 4; ++ j){
                            int x = u[0]+dx[j], y = u[1]+dy[j];
                            if (x<1||x>n||y<1||y>m||col[x][y]||g[x][y]=='#') continue;
                            brake = 0;
                            col[x][y] = i;
                            qs.push({x,y});
                        }
                    }
                    if (brake) break;
                    Q[i] = move(qs);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            ++ cnt[col[i][j]];
    
    for (int i = 1; i <= p; ++ i) cout << cnt[i] << "\n "[i < p];
}
