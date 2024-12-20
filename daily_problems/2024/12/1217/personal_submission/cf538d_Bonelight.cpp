/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e9
#define INFF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n; cin >> n;
    auto bound = [&](int x, int y){return x >= 0 && x < n && y >= 0 && y < n;};

    vector<string> g(n); For(i,0,n-1) cin >> g[i];
    vector<vector<char>> ans(2*n-1,vector<char>(2*n-1,'x'));
    For(x1,0,n-1) For(y1,0,n-1) {
        if(g[x1][y1] == 'o') 
        For(x2,0,n-1) For(y2,0,n-1){
            if(g[x2][y2] == '.') ans[(x2 - x1) + (n-1)][(y2 - y1) + (n-1)] = '.';
        }
    }
    ans[n-1][n-1] = 'o';

    For(x1,0,n-1) For(y1,0,n-1) {
        if(g[x1][y1] == 'x'){
            bool ok = false;
            For(x2,0,2*n-2) For(y2,0,2*n-2){
                if(ans[x2][y2] == 'x'){
                    int nx = x1 - (x2-(n-1)), ny = y1 - (y2-(n-1));
                    if(bound(nx,ny) && g[nx][ny] =='o') ok = true;
                }
            }
            if(!ok) return void(cout << "NO" << endl);
        } 
    }
    cout << "YES" << endl;
    for(auto uni:ans) {
        for(auto i:uni){
            cout << i;
        }
        cout << endl;
    }

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
}
