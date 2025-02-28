/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define int long long
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
    int n,m,k; cin >> n >> k;
    vector<string> g(4, string(n,'.'));
    cout << "YES" << endl;
    if(k % 2 == 1){
        if(k > n-2) {
            int cnt = (k-(n-2))/2;
            g[1] = "." + string(n-2,'#') + ".";
            For(i, 1, cnt) g[2][n/2 + i] = '#', g[2][n/2 - i] = '#';
        } else {
            int cnt = k/2;
            g[1][n/2] = '#';
            For(i,1,cnt) g[1][n/2 + i] = '#', g[1][n/2 - i] = '#';
        }
    } else if(k % 2 == 0){
        if(k > n-2) {
            int cnt = (k-(n-2))/2;
            g[1] = "." + string(n-2,'#') + ".";
            For(i, 0, cnt) g[2][n/2 + i] = '#', g[2][n/2 - i] = '#';
        } else {
            int cnt = k/2;
            For(i,1,cnt) g[1][n/2 + i] = '#', g[1][n/2 - i] = '#';
        }

    }

    for(auto i:g) cout << i << endl;
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
