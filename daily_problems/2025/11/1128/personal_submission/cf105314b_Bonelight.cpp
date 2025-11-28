/*
    Bonelight (=v=)
    20251128 https://codeforces.com/gym/105314/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
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
    int n,m; cin >> n >> m;
    VC a(n); For(i,0,n) cin >> a[i];
    sort(all(a));

    int l = -1, r = 1e7;
    while(l + 1 < r){
        int mid = l + r >> 1;

        int cnt = 0, pt = 0;
        For(i,0,n){
            while(pt < n && a[pt] - a[i] < mid){
                pt ++;
            }
            cnt += 2*(n-pt);
        }

        if(cnt <= m) r = mid;
        else l = mid;
    }
    
    int bound = r, pt = 0;
    int cnt = 0;
    int ans = 0;

    VC prev(n+1);
    For(i,0,n){
        prev[i+1] = prev[i] + a[i];
    }

    For(i,0,n){
        while(pt < n && a[pt] - a[i] < bound) pt ++;
        cnt += 2*(n-pt);
        ans += 2*(prev[n] - prev[pt] - (n-pt)*a[i]);
    }

    ans += (m - cnt) * (bound-1);
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
