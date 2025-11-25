/*
    Bonelight (=v=)
    20251124 https://codeforces.com/gym/105712/problem/B
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
    VC nums(n);
    int res = 0;
    For(i,0,n) cin >> nums[i];  
    int mx = *max_element(all(nums));
    
    if(mx < 2) cout << 0 << endl;
    else if(n == 2){
        while(nums[0] > 1 || nums[1] > 1){
            int add1 = nums[0]/2, add2 = nums[1]/2;
            nums[0] %= 2; nums[1] %= 2;
            nums[0] += add2, nums[1] += add1;
            res += add1 + add2;
        }
        cout << res << endl;
    } else {
        int tot = accumulate(all(nums), 0ll);
        cout << (tot == 3 && mx == 3? 1LL:tot-1) << endl; 
    }
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
