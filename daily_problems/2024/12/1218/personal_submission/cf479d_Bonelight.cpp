/*
    Bonelight (=v=)
    20241211: New Light
    == Under Fire == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e9
#define INFF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n,len,x,y; cin >> n >> len >> x >> y;
    VC a(n); For(i,0,n-1) cin >> a[i];
    unordered_set<int> st;
    For(i,0,n-1) st.insert(a[i]);

    auto check = [&](int d) ->VC {
        VC res;
        For(i,0,n-1){
            if(st.count(a[i] - d)) res.push_back(a[i]-d);
        }
        return res;
    };

    int fx = check(x).size(), fy = check(y).size();
    if(fx && fy) cout << "0";
    else if(fx) cout << "1\n" << y;
    else if(fy) cout << "1\n" << x;
    else {
        if(check(x+y).size()) return void(cout << "1\n" << check(x+y)[0] + x);  

        for(auto v:check(y-x)){
            if(v-x >= 0) return void(cout << "1\n" << v-x);
            if(v+y <= len) return void(cout << "1\n" << v+y);
        } 
        cout << "2\n" << x << ' ' << y;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
}
