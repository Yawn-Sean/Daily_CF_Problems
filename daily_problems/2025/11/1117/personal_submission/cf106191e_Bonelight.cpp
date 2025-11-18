/*
    Bonelight (=v=)
    20251115 https://codeforces.com/gym/106191/problem/E
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

    cout << "?";
    For(i,0,2){
        cout << ' ' << n;
        ForR(j,1,n){
            cout << ' ' << j;
        }
    }
    cout << endl;

    int tot; cin >> tot;
    int sum = 0;
    
    ForR(x,1,n-1){
        cout << "?";
        For(i,0,2){
            cout << ' ' << n-1;
            ForR(j,1,n){
                if(j!=x) cout << ' ' << j;
            }
        }
        cout << endl;

        int t; cin >> t;
        if(tot - t == 1) return void(cout << "! " << x << endl);
        sum += tot - t;
    }

    if(tot*2 - sum == 1) cout << "! " << n << endl;
    else cout <<  "! -1" << endl;
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
