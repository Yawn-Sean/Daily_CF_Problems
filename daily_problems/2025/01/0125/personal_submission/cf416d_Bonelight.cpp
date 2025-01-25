/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf416d
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
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
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n; cin >> n; 
    VC a(n); For(i,0,n-1) cin >> a[i];
    int st = 0, x1=-1, x2=-1;
    int ans = 1;

    For(i,0,n-1){
        if(a[i] == -1){ // 公差可知
            if(x2 != -1){
                int nx = a[x1] + (a[x2]-a[x1]) / (x2-x1) * (i-x1);
                if(nx <= 0){
                    ans ++, st = i, x1 = -1, x2 = -1;
                }
            }
        } else {
            if(x1 == -1) x1 = i;
            else if(x2 == -1){
                if((a[i] - a[x1]) % (i - x1) || a[x1] + (a[i] - a[x1]) / (i - x1) * (st-x1) <= 0){
                    ans ++, st = i, x1 = i, x2 = -1;
                } else {
                    x2 = i;
                }
            } else {
                int nx = a[x1] + (a[x2]-a[x1]) / (x2-x1) * (i-x1);
                if(nx != a[i]){
                    ans ++, st = i, x1 = i, x2 = -1;
                }
            }
        }
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
