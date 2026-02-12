/*
    Bonelight (=v=)
    20251128 https://codeforces.com/gym/105314/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'
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
    map<int,vector<int>> mp;

    For (i,0,n) {
        vector<int> num(m);
        For(j,0,m) cin >> num[j];
        mp[num[0]] = num;
    }

    if(n % 2 == 0) {
        for(auto uni:mp){
            for(auto x:uni.y) cout << x << " ";
        }
        cout << endl;
    } else {
        vector<int> st = (*mp.begin()).y;
        For(i,0,n){
            For(j,0,m/2){
                cout << st[j] << " ";
            }
            st = mp[st[m/2]];
        }
        cout << endl;
    }
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
