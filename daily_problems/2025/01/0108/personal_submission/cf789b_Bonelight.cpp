/*
    Bonelight (=v=)
    20250110: 写屑代码一个笨蛋
    == UnderLight == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
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

void solve(){
    int b,q,l,m; cin >> b >> q >> l >> m;
    set<int> st;
    while(m --) {int t; cin >> t; st.insert(t);}

    if(q == 0){
        if(abs(b) <= l){
            if(st.count(0)) {
                cout << 1 - st.count(b) << endl;
            } else {
                cout << "inf" << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }     
    else if(b == 0) cout << ((1 - st.count(0))? "inf":"0") << endl;
    else if(q == 1){
        int ok;
        if(abs(b) <= l) ok = 1 - st.count(b);
        else return void(cout << 0 << endl);

        if(ok) return void(cout << "inf" << endl);
        else return void(cout << 0 << endl);
    }     
    else if(q == -1){
        if(abs(b) <= l) cout << ((2 - st.count(b) - st.count(-b))? "inf":"0") << endl;
        else cout << 0 << endl;
    } else {
        int now = b;
        int ans = 0;
        while(abs(now) <= l){
            if(!st.count(now)) ans ++;
            now *= q;
        }
        cout << ans << endl;
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
