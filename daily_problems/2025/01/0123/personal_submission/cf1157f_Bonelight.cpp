/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1157f
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
    VC cnt(2e5 + 2);
    int n; cin >> n;
    VC a(n + 1); For(i,1,n) cin >> a[i], cnt[a[i]] ++;

    int st = 0, ed = 0, ans = 0;
    int p = 1;

    while(p <= 2e5){
        if(cnt[p] >= 2){
            int l = p, t = 0;
            while(cnt[p] >= 2){
                t += cnt[p];
                p ++;
            }
            if(cnt[l-1]) t ++;
            if(cnt[p]) t ++;
            if(t > ans) st = l, ed = p-1, ans = t;
        } else {
            p ++;
        }
    }

    if(ans >= 2){
        cout << ans << endl;
        if(cnt[st-1]) cout << st-1 << ' '; // mi + [l-r] + mx + [r-l]
        For(i,st,ed) cout << i << ' ';
        if(cnt[ed+1]) cout << ed+1 << ' ';
        Rof(i,ed,st){
            For(j,1,cnt[i]-1) cout << i << ' ';
        }
        cout << endl;
    } else {
        For(i,1,2e5){
            if(cnt[i]&&cnt[i+1]) return void(cout << "2\n" << i << ' ' << i + 1 << endl);
        }

        cout << "1\n" << a[1] << endl;
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
