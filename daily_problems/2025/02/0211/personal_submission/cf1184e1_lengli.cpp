/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

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
	int res=-1;
	
	void build(int n,std::vector<std::array<int,3>> edge){
		sort(edge.begin()+1,edge.end(),[&](auto l,auto r){
			return l[2]<r[2];
		});
		DSU dsu(n+1);
		for(int i=1;i<edge.size();i++){
            auto [u,v,w]=edge[i];
			if(dsu.same(u,v)) continue;
			dsu.merge(u,v);
            if(dsu.same(edge[0][0],edge[0][1])){
                res=w;
                return;
            }
		}
		res=1e9;
	}
}kt;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,3>> edge(m);
    for(auto &[x,y,z]:edge) std::cin>>x>>y>>z;
    kt.build(n,edge);
    std::cout<<kt.res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
