/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
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
#define x first
#define y second

void solve(){
    int n,q; cin >> n >> q;
    VCii a(n); For(i,0,n-1) cin >> a[i].x >> a[i].y;

    MAT mt(1010, VC(1010));
    
    for(auto [x,y]:a) {
        mt[x][y] += x*y;
        // mt[x+1][y+1] += x*y;
        // mt[x+1][y] -= x*y;
        // mt[x][y+1] -= x*y;
    } 

    For(i,1,1000)
    For(j,0,1000){
        mt[i][j] += mt[i-1][j];
    }
    
    For(i,0,1000)
    For(j,1,1000){
        mt[i][j] += mt[i][j-1];
    }

    while(q --){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 ++, y1 ++, x2 --, y2 --;
        cout << mt[x1-1][y1-1] + mt[x2][y2] - mt[x2][y1 - 1] - mt[x1 - 1][y2] << endl;
    }

    // cout << endl; //
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; cin >> T;
    while(T --) solve();
    return 0;
}
