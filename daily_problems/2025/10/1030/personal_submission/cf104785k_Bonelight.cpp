/*
    Bonelight (=v=)
    20251027 Bonelight's submission for cf105613e
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

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    int n,m; cin >> n >> m;
    VC a,b; 

    For(i,1,m) {
        int x,y; cin >> x >> y;
        if(x > y) a.push_back(i);
        else b.push_back(i);
    }
    cout << "YES" << endl;
    if(a.size() > b.size()){
        cout << a.size() << endl;
        for(auto i:a) cout << i << ' ';
    } 
    else{
        cout << b.size() << endl;
        for(auto i:b) cout << i << ' ';
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
