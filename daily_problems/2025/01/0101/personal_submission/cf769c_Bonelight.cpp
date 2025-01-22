/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
    #pragma GCC optimize(2)
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<string> g(n); For(i,0,n-1) cin >> g[i];
    
    if(k % 2 == 1) return void(cout << "IMPOSSIBLE" << endl);

    For(i,0,n-1) For(j,0,m-1){
        if(g[i][j] == 'X'){
            auto check = [&](int x, int y){return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*';};
            vector<tuple<int,int,char>> df = {{1,0,'D'},{0,-1,'L'},{0,1,'R'},{-1,0,'U'}};
            queue<pii> q; q.emplace(i,j);
            MAT dist(n,VC(m,-1));
            dist[i][j] = 0;
            while(q.size()){
                auto [x,y] = q.front(); q.pop();
                for(auto [dx,dy,c]:df){
                    int nx = x + dx, ny = y + dy;
                    if(check(nx,ny) && dist[nx][ny] == -1){
                        q.emplace(nx, ny);
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
            // For(i1,0,n-1) For(i2,0,m-1) {
            //     cout << dist[i1][i2] << " \n"[i2 == m-1];
            // }
            int x = i, y = j; 
            string ans;
            while(k --){
                for(auto [dx, dy, c]:df){
                    int nx = dx + x, ny = dy + y;
                    if(check(nx,ny) && dist[nx][ny] <= k){
                        ans += c;
                        x = nx, y = ny;
                        break;
                    }    
                }
            }
            if(ans.size()) cout << ans << endl;
            else cout << "IMPOSSIBLE" << endl;
        }
    }


}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;
    while(T --) solve();
    return 0;
}
