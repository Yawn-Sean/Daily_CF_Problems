/*
    Bonelight (=v=)
    20251127 https://codeforces.com/gym/106197/problem/C
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
    int n; cin >> n;
    auto query = [&](int x, int y){
        cout << "? " << x << ' ' << y << endl;
        int val; cin >> val;
        return val;
    };

    int p1 = 1;
    ForR(i,2,n){
        if(query(p1,i) != p1) p1 = i;
    }

    VC cur,ans; 
    ForR(i,1,n) {
        if(i != p1) cur.emplace_back(i);
    }

    while(cur.size()){
        VC ncur;
        int p = cur[0], sz = cur.size();
        For(i,1,sz){
            int val = query(cur[i],p);
            if(val == p1){
                ncur.emplace_back(cur[i]);
            } else {
                p = val;
            }
        }
        cur.swap(ncur);
        ans.emplace_back(p);
    }

    cout << "! " << ans.size();
    for(auto i:ans) cout << ' ' << i;
    cout << endl;
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
