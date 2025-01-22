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
    int n,k; cin >> n >> k;
    VC a(n); For(i,0,n-1) cin >> a[i];

    int mx = *max_element(all(a));
    int mi = *min_element(all(a));

    // poor
    int l = mi - 1;
    i64 r = accumulate(all(a),0ll) / n + 1;
	// cout << l << ' ' << r << endl;
    while(l + 1 < r){
        i64 mid = r + l >> 1;
        //check
        i64 cnt = 0;
        For(i,0,n-1) if(a[i] < mid){
            cnt += mid - a[i];
            if(cnt > k) {r = mid; break;}
        }
        if(cnt <= k) l = mid;
    }
    int poor = l;

    // rich
    l = (accumulate(all(a),0ll) + n - 1) / n - 1;
    r = mx + 1;

    while(l + 1 < r){
        i64 mid = r + l >> 1;
        //check
        i64 cnt = 0;
        For(i,0,n-1) if(a[i] > mid){
            cnt += a[i] - mid;
            if(cnt > k) {l = mid; break;}
        }
        if(cnt <= k) r = mid;
    }
    int rich = r;
    cout << rich - poor << endl;
    // cout << poor << ' ' << rich << endl;
    // cout << mi << ' ' << mx << ' ' << accumulate(all(a),0ll) << endl;
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
