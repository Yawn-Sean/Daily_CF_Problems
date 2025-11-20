/*
    Bonelight (=v=)
    20251119 https://codeforces.com/gym/106007/problem/D
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

int op(int x, int y) {return min(x,y);}
int e() {return 1e9;}
void solve(){
    int n; cin >> n;
    vector<string> g(n);

    For(i,0,n){
        cin >> g[i];
    }

    VCii ans;
    VC vis(n); vis[0]=1;
    queue<int> q; q.push(0);
    while(q.size()){
        int x = q.front(); q.pop();
        For(y,0,n){
            if(vis[y]) continue;
            if(g[x][y] != '0'){
                q.push(y); vis[y] = 1; 
                ans.push_back({x,y});
            } 
        }
    }

    For(i,0,n){
        if(vis[i] == 0) return void(cout << "No" << endl); 
    }

    cout << "Yes" << endl;
    reverse(all(ans));
    for(auto [x,y]:ans){
        cout << x+1 << ' ' << y+1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1;cin >> T;
    while(T --) solve();
    return 0;
}
