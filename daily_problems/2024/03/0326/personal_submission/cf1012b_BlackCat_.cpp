#include<bits/stdc++.h>
#define endl '\n'
using i64 =long long;
/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
    std::vector<int> f;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};
void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    i64 ans=1ll*n+m-1;
    DSU dsu(n+m+10);
    while(q--){
        int x,y;
        std::cin>>x>>y;
        if(dsu.merge(x,y+n)){
            ans--;
        }
    }
    std::cout<<ans<<endl;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
}
