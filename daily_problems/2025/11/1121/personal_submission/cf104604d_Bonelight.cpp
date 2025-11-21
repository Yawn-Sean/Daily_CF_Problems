/*
    Bonelight (=v=)
    20251120 https://codeforces.com/gym/104536/problem/E
*/

#include <bits/stdc++.h>
// #include <atcoder/segtree>
// using namespace atcoder;
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
    int a,b; cin >> a >> b;
    
    if(a > b) swap(a,b);
    
    int oka = 0, okb = 0;
    
    if(b > 2*a) cout << "NO" << endl;
    else if(a == b){
        if(a % 2 == 0) cout << "SI" << endl;
        else cout << "NO" << endl;
    } else {
        if(a % (b-a) != 0) cout << "NO" << endl;
        else {
            int ok = 0;
            ForR(i,2,4){
                if(b % i == 0){
                    int x = a - b/i;
                    if(x > 0 && b % x == 0){
                        ok = 1;
                        break;
                    }
                }
            }

            if(ok) cout << "SI" << endl;
            else cout << "NO" << endl;
        }
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
