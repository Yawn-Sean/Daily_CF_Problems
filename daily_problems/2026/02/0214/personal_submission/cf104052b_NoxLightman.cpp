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
    MAT mp = {
        {2,1,1,0},
        {2,0,2,0},
        {1,1,2,1}
    };
    VC nums(4); For(i,0,4) cin >> nums[i];
    int ans = INF;
    For(i,0,16){ 
        int cur = 0;
        For(j,0,4){
            if(i >> j & 1){
                cur += nums[j];
            }
        }

        int to_check = INF;
        For(j,0,3){
            int val = 0;
            For(k,0,4){
                if(i >> k & 1){
                    val += mp[j][k];
                }
            }
            to_check = min(to_check, val);
        }
        if(to_check) ans = min(ans, cur / to_check);
    }
    cout << ans << endl;
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
