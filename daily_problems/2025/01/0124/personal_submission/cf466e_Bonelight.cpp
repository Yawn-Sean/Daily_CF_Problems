/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf466e
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
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
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

class UnionFind{
  public:
    VC X;
    UnionFind(int n){
        X.resize(n);
        For(i,0,n-1) X[i] = i;
    }

    int find(int x){
        return X[x] = X[x]==x? x:find(X[x]); 
    }

    void merge(int xx, int yy) {
        int x = find(xx), y = find(yy);
        if(x!=y) X[x] = y;
    }
};

void solve(){
    int n,q; cin >> n >> q;
    VC ts(q),xs(q),ys(q);
    MAT g(n+1, VC());
    VC fa(n+1);


    For(i,0,q-1){
        cin >> ts[i] >> xs[i];
        if(ts[i] != 2) cin >> ys[i];
        if(ts[i] == 1) fa[xs[i]] = ys[i];
    }
    For(i,1,n){
        int root = fa[i];
        g[root].push_back(i);
        g[i].push_back(root);
    }

    VC ls(n+1,-1), rs(n+1,-1);
    int tmp = 0;
    
    function<void(int)> dfs = [&](int o){
        ls[o] = tmp;
        tmp++;
        for(auto p:g[o]){
            if(fa[p] == o) dfs(p);
        }
        rs[o] = tmp;
    };
    dfs(0);

    UnionFind dsu(n+1);

    VC st(1), ed(1);
    For(i,0,q-1){
        int t=ts[i],x=xs[i],y=ys[i];
        if(t == 1){
            dsu.merge(x,y);
        } else if (t == 2){
            st.push_back(x);
            ed.push_back(dsu.find(x));
        } else if (t == 3){
            int l = st[y], r = ed[y];
            cout << (ls[r]<=ls[x] && ls[x]<=ls[l] 
                && rs[l]<=rs[x] && rs[x]<=rs[r] ? "YES":"NO") << endl;
        }
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
