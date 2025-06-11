#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    int n, m, q, p;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    int res[300][300];
    memset(res, 0, sizeof(res));
    cin >> n >> m >> q >> p;
    vector<string>mp(n);
    for(int i = 0; i < n; i++){
        cin >> mp[i];
    }
    auto bfs = [&](int sx, int sy, int noise) -> void{
        queue<PII>que;
        que.push({sx, sy});
        res[sx][sy] += noise;
        int check[300][300];
        int tmp[300][300];
        memset(check, false, sizeof(check));
        check[sx][sy] = true;
        while(!que.empty() && noise > 0){
            noise /= 2;
            int size = que.size();
            for(int i = 0; i < size; i++){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int k = 0; k < 4; k++){
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if(tx < 0 || ty < 0 || tx >= n || ty >= m)continue;
                    if(mp[tx][ty] != '*' && !check[tx][ty]){
                        check[tx][ty] = true;
                        res[tx][ty] += noise;
                        tmp[tx][ty] += noise;
                        que.push({tx, ty});
                    }
                }
            }
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] >= 'A' && mp[i][j] <= 'Z'){
                int noise = mp[i][j] - 'A' + 1;
                bfs(i, j, noise * q);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(res[i][j] > p)ans++;
            // cout << res[i][j] << " ";
        }
        // cout << '\n';
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
