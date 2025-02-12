/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf518a
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
    string a,b; cin >> a >> b;
    int n = a.size();
    Rof(i,n-1,0){
        if(a[i] !=  'z') {a[i]++; break;}
        else a[i] = 'a';
    }

    if(a != b) cout << a << endl;
    else cout << "No such string" << endl;

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
