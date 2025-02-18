/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

int n,m,k,w;
char g[1001][10][10];
int rd[1001],f[1001];

struct DSU{
    std::vector<int> p, sz,add;
    DSU(int n): p(n), sz(n, 1),add(n,0){
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
    }
    int sum(int x){
    	return x == p[x] ? add[x] : add[x]+sum(p[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if(size(x) < size(y)) std::swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        add[y]-=add[x];
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

struct kurskal{
	std::vector<std::vector<int>> g;
	int cnt,sum;
	
	void build(int n,std::vector<std::array<int,3>> edge){
		cnt=0,sum=0;
		sort(edge.begin(),edge.end(),[&](auto l,auto r){
			return l[2]<r[2];
		});
		DSU dsu(n+1);
        std::vector<int> st(n+2);
        g.resize(n+2);
		for(auto [u,v,w]:edge){
			if(dsu.same(u,v)) continue;
			sum+=w;
			dsu.merge(u,v);
			g[u].pb(v);
            g[v].pb(u);
		}
		cnt=dsu.size(0);
	}
}kt;

void solve(){
    std::cin>>n>>m>>k>>w;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++) std::cin>>g[i][j][k];
        }
    }

    auto get=[&](int l,int r){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[l][i][j]!=g[r][i][j]) cnt++;
            }
        }
        return cnt;
    };

    std::vector<std::array<int,3>> edge;

    for(int i=1;i<=k;i++){
        edge.pb({0,i,n*m});
        for(int j=1;j<=k;j++) {
            if(i==j) continue;
            int v=get(i,j)*w;
            edge.pb({j,i,v});
        }
        
    }

    kt.build(k,edge);
    std::cout<<kt.sum<<"\n";
    auto dfs=[&](auto self,int u,int fa)->void{
        if(fa!=-1) std::cout<<u<<" "<<fa<<"\n";
        for(auto x:kt.g[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
    };
    dfs(dfs,0,-1);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
