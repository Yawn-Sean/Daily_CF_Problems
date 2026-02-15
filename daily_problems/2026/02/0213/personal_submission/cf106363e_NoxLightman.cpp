/*
    Bonelight (=v=)
    20251128 https://codeforces.com/gym/105314/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF (int)2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define ForR(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define RofR(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define For(_i,_l,_r) for(int _i = _l; _i < _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i > _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n; cin >> n;
    VC nums(n); For(i,0,n) cin >> nums[i];
    VC pos(n); For(i,0,n) pos[nums[i]] = i;
    
    int l = pos[0], r = pos[0];

    VC diff_0(n+1), diff_1(n+1);

    For(i,0,n){
        l = min(l,pos[i]);
        r = max(r,pos[i]);

        diff_0[l] += (n - r) * (l + 1);
    		diff_0[r + 1] -= (n - r) * (l + 1);
    
    		diff_1[0] += n - r;
    		diff_1[l] -= n - r;
    		diff_0[0] += n - r;
    		diff_0[l] -= n - r;
    
    		diff_1[r + 1] -= l + 1;
    		diff_1[n] += l + 1;
    		diff_0[r + 1] += (l + 1) * n;
    		diff_0[n] -= (l + 1) * n;
    }

    For(i,0,n){
        diff_0[i+1] += diff_0[i];
        diff_1[i+1] += diff_1[i];
        cout << diff_1[i] * i + diff_0[i] << endl;
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
