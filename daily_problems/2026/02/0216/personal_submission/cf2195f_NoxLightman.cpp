/*
    Bonelight (=v=)
    20251128 https://codeforces.com/gym/105314/problem/A
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
    int n; cin >> n;
    vector<array<int,3>> func(n);
    
    For(i,0,n){
        int a,b,c; cin >> a >> b >> c;
        func[i] = {a,b,c};
    }
    VC order(n); iota(all(order), 0);
    sort(all(order), [&](int x, int y){
        return func[x][2] < func[y][2];
    });
    VC dp_down(n,1), dp_up(n,1);
    For(i,1,n){
        For(j,0,i){
            int vi = order[i], vj = order[j];
            auto [a1,b1,c1] = func[vi];
            auto [a2,b2,c2] = func[vj];
            int a = a1-a2, b = b1-b2, c = c1-c2;
            if(a==0){
                if(b==0) dp_up[vi] = max(dp_up[vi], dp_up[vj] + 1); 
            } else {
                if(b*b < 4*a*c) dp_up[vi] = max(dp_up[vi], dp_up[vj] + 1);
            }
        }
    }

    RofR(i,n-1,0){
        For(j,i+1,n){
            int vi = order[i], vj = order[j];
            auto [a1,b1,c1] = func[vi];
            auto [a2,b2,c2] = func[vj];
            int a = a1-a2, b = b1-b2, c = c1-c2;
            if(a==0){
                if(b==0) dp_down[vi] = max(dp_down[vi], dp_down[vj] + 1); 
            } else {
                if(b*b < 4*a*c) dp_down[vi] = max(dp_down[vi], dp_down[vj] + 1);
            }
        }
    }

    For(i,0,n){cout << dp_up[i] + dp_down[i] - 1 << ' ';}
    cout << endl;
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
