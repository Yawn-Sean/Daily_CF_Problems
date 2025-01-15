/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 总所周知，史官就是写 shi 的嘛 == 
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
    string s; getline(cin, s);
    int plus = 1, sub = 0, n = 0;
    for(auto ch:s) {
        plus += (ch == '+');
        sub += (ch == '-');
        if(isdigit(ch)) n = 10 * n + (ch - '0');
    }
    int num = plus + sub;
    if( plus * n - sub < n) return void(cout << "Impossible");
    if( plus - sub * n > n) return void(cout << "Impossible");
    
    cout << "Possible" << endl;
    int sign = 0;
    int now = n - (plus * 1 - sub * n);
    for(auto ch:s){
        if(ch == '+') sign = 0; 
        if(ch == '-') sign = 1;

        if(ch == '?'){
            int t = sign? -n:1;
            int add = 0;
            if(now >= n - 1) {add = n-1; now -= n - 1;}
            else {add = now; now = 0;}
            cout << abs(t + add);
        } 
        else cout << ch;
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
