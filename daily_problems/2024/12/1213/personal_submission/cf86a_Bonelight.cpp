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
    int l,r; cin >> l >> r;
    int w = log10(r);
    int mid = pow(10ll,w+1) / 2 - 1;
    
    if(l <= mid && mid <= r) cout << mid*((int)pow(10ll, w+1) - 1) - mid*mid << endl;
    else if(l <= mid && r <= mid) cout << r*((int)pow(10ll, w+1) - 1) - r*r << endl;
    else cout << l*((int)pow(10ll, w+1) - 1) - l*l << endl;
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
