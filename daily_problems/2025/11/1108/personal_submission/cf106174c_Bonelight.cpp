/*
    Bonelight (=v=)
    20251103 Bonelight's submission for 106159/problem/D
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
    int n,k; cin >> n >> k;
    
    auto prev = [&](int x){
        int st = 1, ans = 0, d = 1;
        
        for(int i = 0; i < 18; i ++){
            if(st > x) break;
            ans += min(st * 9, x - st + 1) * d;
            st *= 10;
            d ++;
        }
        return ans;
    };
    
    int l = 0, r = 5e17;
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(prev(mid+n-1) - prev(mid-1) >= k) r = mid;
        else l = mid;
    }
    
    if(prev(r+n-1) - prev(r-1) == k) cout << r << endl;
    else cout << -1 << endl; 
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
