/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct HopcroftKarp {//idx_start_1
	std::vector<int> g,l,r;
	int ans;
	HopcroftKarp(int n,int m,const std::vector<std::array<int,2>> &e): g(e.size()+2),l(n+2, -1),r(m+2, -1),ans(0){
		std::vector<int> deg(n+2);
		for(auto &[x, y]:e) deg[x]++;
		for(int i=1;i<=n+1;i++) deg[i]+=deg[i-1];
		for(auto &[x, y]:e) g[--deg[x]]=y;
		std::vector<int> q(n+2);
		while(true){
			std::vector<int> a(n+2,-1),p(n+2,-1);
			int t=0;
			for(int i=1;i<=n;i++) if(l[i]==-1)
				q[t++]=a[i]=p[i]=i;
			bool match=false;
			for(int i=0;i<t;i++) {
				int x=q[i];
				if(~l[a[x]]) continue;
				for(int j=deg[x];j<deg[x+1];j++) {
					int y=g[j];
					if(r[y]==-1) {
						while(~y) r[y]=x,std::swap(l[x],y),x=p[x];
						match=true,ans++;
						break;
					}
					if(p[r[y]]==-1)
						q[t++]=y=r[y],p[y]=x,a[y]=a[x];
				}	
			}
			if(!match) break;
		}
	}
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,3>> edge;
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        edge.pb({u,v,w});
    }
    int l=1,r=1000000000;

    auto check=[&](int x){
        std::vector<std::array<int,2>> tmp;
        for(auto [u,v,w]:edge){
            if(w<=x) tmp.pb({u,v});
        }
        HopcroftKarp tr(n,n,tmp);
        return tr.ans==n;
    };

    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(!check(r)) r=-1;
    std::cout<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
