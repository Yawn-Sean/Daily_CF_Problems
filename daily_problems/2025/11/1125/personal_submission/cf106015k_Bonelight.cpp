/*
    Bonelight (=v=)
    20251125 https://codeforces.com/gym/106015/problem/K
*/
#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP

#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
using namespace atcoder;

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
    vector<tiii> nums(m), to_check;
    for(auto &[w,x,y]:nums) cin >> x >> y >> w, x--, y--;
    MATii g(n, VCii());
    
    sort(all(nums));
    atcoder::dsu uni(n);

    for(auto &[w,x,y]:nums){
        if(!uni.same(x,y)){
            uni.merge(x,y);
            g[x].emplace_back(y,w);
            g[y].emplace_back(x,w);
        } else {
            to_check.emplace_back(w,x,y);
        }
    }

    VC dep(n),to_root(n);
    MAT nfa(20, VC(n,-1));

    auto dfs = [&](auto &self, int o, int fa) -> void {
        for(auto [p,w]:g[o]) if(p != fa){
            dep[p] = dep[o] + 1;
            to_root[p] = to_root[o] + w;
            nfa[0][p] = o;
            self(self,p,o);
        }
    };

    dfs(dfs,0,-1);

    For(i,0,19){
        For(j,0,n){
            if(nfa[i][j] >= 0) nfa[i+1][j] = nfa[i][nfa[i][j]];
        }
    }

    auto lca = [&](int x, int y){
        if(dep[x] > dep[y]) swap(x,y);
        int d = dep[y] - dep[x];
        while(d) {
            int t = d & -d;
            y = nfa[__builtin_ctz(t)][y];
            d -= t;
        }

        if(x == y) return x;

        RofR(i,19,0){
            if(nfa[i][x] != nfa[i][y]){
                x = nfa[i][x];
                y = nfa[i][y];
            }
        }
        return nfa[0][x];
    };

    for(auto &[w,x,y]:to_check){
        int fa = lca(x,y);
        if(to_root[x] + to_root[y] - 2*to_root[fa] > w){
            return void(cout << "NO" << endl);
        }
    }
    cout << "YES" << endl;
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
