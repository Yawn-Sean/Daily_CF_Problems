// Problem: F2. Spanning Tree with One Fixed Degree
// Contest: Codeforces - Codeforces Round 544 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1133/F2
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
    DSU(int n): p(n+1), sz(n+1, 1),add(n+1,0){
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

void solve(){
	int n,m,d;
	std::cin>>n>>m>>d;
	std::vector<std::array<int,2>> edge(m);
	
	DSU dsu(n+1);
	std::vector<int> link;
	
	for(auto &[x,y]:edge){
		std::cin>>x>>y;
		if(x>y) std::swap(x,y);
		if(x!=1) dsu.merge(x,y);
		else link.pb(y);
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(dsu.find(i)==i) cnt++;
	}
	if(cnt>d or (int)link.size()<d){
		std::cout<<"NO"<<"\n";
		return;
	}
	DSU ans(n+1);
	std::vector<std::array<int,2>> res;
	std::vector<int> st(n+2,0);
	for(auto [u,v]:edge){
		if(u==1 and (int)res.size()<d){
			if(ans.same(u,v) or st[dsu.find(v)]) continue;
			res.pb({u,v});
			ans.merge(u,v);
			st[dsu.find(v)]=1;
		}
	}
	
	for(int i=0;i<link.size() and (int)res.size()<d;i++){
		int v=link[i];
		if(ans.same(1,v)) continue;
		ans.merge(1,v);
		res.pb({1,v});
	}
	
	for(auto [u,v]:edge){
		if(ans.same(u,v)) continue;
		if(u!=1){
			ans.merge(u,v);
			res.pb({u,v});
		}
	}
	
	std::cout<<"YES"<<"\n";
	for(auto [x,y]:res) std::cout<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
