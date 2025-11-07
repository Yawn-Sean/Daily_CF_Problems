/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1912d 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) begin(_a)+1, end(_a)

#define x first
#define y second
#define ls (o << 1)
#define rs ((o << 1) + 1)
#define ULL unsigned long long

void solve(){
    string s1,s2,op; cin >> s1 >> op >> s2;
    int a = 0 ,b = 0;

    int mod = 1e9 + 7;
    for(char i:s1) a = 10 * a + (i-'0'), a%=mod;
    for(char i:s2) b = 10 * b + (i-'0'), b%=(op == "^"? mod-1:mod);
    
    auto qpow = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = res * x % mod;
            y >>= 1;
            x = x*x%mod;
        }
        return res;
    };

    if(op == "+") cout << (a+b)%mod << endl;
    if(op == "-") cout << (a-b+mod)%mod << endl;
    if(op == "*") cout << (a*b)%mod << endl;
    if(op == "^") cout << qpow(a,b) << endl;
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
