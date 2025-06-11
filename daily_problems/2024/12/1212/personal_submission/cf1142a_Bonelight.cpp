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

void solve(){
    int n,k,a,b; cin >> n >> k >> a >> b;
    int mi = INF, mx = -INF;

    For(i,0,n-1){
        int l = i*k + a + b;
        int add = __gcd(l,n*k); 
        mi = min(mi,n*k / add), mx = max(mx,n*k / add);
        l = i*k + a - b;
        add = __gcd(l,n*k); 
        if(l >= 0){
            add = __gcd(l,n*k); 
            mi = min(mi,n*k / add), mx = max(mx,n*k / add);
        }
    }
    cout << mi << ' ' << mx << endl;
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
