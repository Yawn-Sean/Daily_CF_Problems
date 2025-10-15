/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 总所周知，史官就是写 shi 的嘛 == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n,k,m; cin >> n >> k >> m;
    VC a(k); For(i,0,k-1) cin >> a[i];
    sort(all(a));

    int sum = accumulate(all(a), 0ll);
    int ans = 0;
    For(i1,0,n){
        int t = m - i1*sum, v = i1 * (k+1), r = n - i1;
        if(t < 0) break; 
        For(i2,0,k-1){
            For(i3,1,r){
                t -= a[i2];
                if(t < 0) break; 
                v ++;
            }
            if(t < 0) break;
        }
        ans = max(ans, v);
    }
    cout << ans << endl;
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
