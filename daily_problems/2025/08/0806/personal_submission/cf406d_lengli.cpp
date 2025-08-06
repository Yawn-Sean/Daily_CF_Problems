/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct LCA{
    std::vector<int> dep;
    std::vector<std::vector<int>> eg,fa;
    std::vector<int> st;
    int m;
    void init(int n){
        m=log(n)/log(2)+1;
        eg.clear(),dep.clear(),fa.clear();st.clear();
        eg.resize(n+1),dep.resize(n+1,0);st.resize(n+1,0);
        fa.resize(n+1,std::vector<int> (m+1,0));
    }
    
    void dfs(int u, int f) {
        st[u]=1;
        for (int i = 1; i <= m; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto j:eg[u]) {
            if (j == f) continue;
            fa[j][0] = u;
            dep[j] = dep[u] + 1;
            dfs(j, u);
        }
    }
    
    int lca(int a, int b) {
        if (dep[a] < dep[b]) std::swap(a, b);
        for (int i = m; i >= 0; i--) {
            if (dep[a] - (1 << i) >= dep[b]) a = fa[a][i];
        }
        if (a == b) return a;
        for (int i = m; i >= 0; i--) {
            if (fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    }
}tr;

bool Cross(std::array<i64,2> a,std::array<i64,2> &b){
  	return 1ll*a[0]*b[1]-1ll*a[1]*b[0]>0;
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<i64,2>> pt(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>pt[i][0]>>pt[i][1];
    }
    std::vector<int> q(n+2);
    q[n]=n;
    std::stack<int> s;
    s.push(n);
    for(int i=n-1;i>=1;i--){
        while(s.size()>=2){
            auto a=s.top();
            s.pop();
            auto b=s.top();
            std::array<i64,2> A={pt[a][0]-pt[i][0],pt[a][1]-pt[i][1]};
            std::array<i64,2> B={pt[b][0]-pt[i][0],pt[b][1]-pt[i][1]};
            if(!Cross(A,B)){
                s.push(a);
                break;
            }
        }
        if(s.size()) q[i]=s.top();
        else q[i]=i;
        s.push(i);
    }


    tr.init(n+2);

    for(int i=1;i<=n;i++) {
        tr.eg[q[i]].pb(i);
    }

    for(int i=n;i>=1;i--){
        if(!tr.st[i]){
            tr.dfs(i,0);
        }
    }

    int m;
    std::cin>>m;
    while(m--){
        int u,v;
        std::cin>>u>>v;
        std::cout<<tr.lca(u,v)<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
