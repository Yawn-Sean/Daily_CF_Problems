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
    int n; cin >> n;
    int c0 = 0, c1 = 0; 

    For(i,1,n) {
        string s; cin >> s;
        if(s == "===xxx" || s == "xxx===") c0 ++;
        else if(s == ".xx===" || s == "xx.===" || s == "===xx." || s == "===.xx") c1 ++;
    }

    if(c0 % 2 == 1 || c1 % 2 == 1) cout << "Monocarp" << endl;
    else cout << "Polycarp" << endl;

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
