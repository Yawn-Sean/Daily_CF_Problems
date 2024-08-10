/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
	std::vector<std::vector<std::array<int,2>>> g;
	int cnt,sum;
	
	long long build(int n,std::vector<std::array<int,3>> edge,int k){
		g.clear();g.resize(n+1);
		cnt=0,sum=0;
		sort(edge.begin(),edge.end(),[&](auto l,auto r){
			return l[2]<r[2];
		});
		DSU dsu(n+2);
        long long mx=0,res=0,d=1000000000;
		for(auto [u,v,w]:edge){
            d=std::min(d,std::abs(1ll*k-w));
			if(dsu.same(u,v)) continue;
			sum+=w;
			dsu.merge(u,v);
            mx=std::max(1ll*w,mx);
            if(w>k) res+=w-k;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		cnt=dsu.size(1);
        if(mx>=k) return res;
        return d;

	}
}kt;

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;

    std::vector<std::array<int,3>> edge(m);
    for(auto &[u,v,w]:edge) std::cin>>u>>v>>w;
    std::cout<<kt.build(n,edge,k)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
