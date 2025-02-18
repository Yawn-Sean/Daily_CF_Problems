/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#pragma GCC optimize(2)

constexpr int inf=1e9,N=200010;

struct Info{//information
	std::vector<std::vector<int>> a;
	Info() {
        a.clear();
        a.resize(2,std::vector<int> (2,inf));
    };
	friend Info operator + (const Info &a,const Info &b){
		Info res;

		for(int k=0;k<2;k++){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    res.a[i][j]=std::min(res.a[i][j],a.a[i][k]+b.a[k][j]+1);
                }
            }
        }

		return res;
	};
};

struct Segment_tree{
	Info info[N*4];
	
	void pushup(int u){
		info[u]=info[u<<1]+info[u<<1|1];
	}
	
	void build(int u,int l,int r,std::vector<std::vector<char>> &g){
		if(l==r) {
			if(g[0][l]=='.') info[u].a[0][0]=0;
            if(g[1][l]=='.' and g[0][l]=='.') info[u].a[0][1]=1;
            if(g[1][l]=='.') info[u].a[1][1]=0;
            if(g[1][l]=='.' and g[0][l]=='.') info[u].a[1][0]=1;
		}else{
			int mid=(l+r)>>1;
			build(u<<1,l,mid,g);
			build(u<<1|1,mid+1,r,g);
			pushup(u);
		}
	}
	
	Info query(int u,int l,int r,int pl,int pr){
		if(l>=pl and r<=pr) return info[u];
		int mid=(l+r)>>1;
		if(pl>mid) return query(u<<1|1,mid+1,r,pl,pr);
		else if(pr<=mid) return query(u<<1,l,mid,pl,pr);
		else return query(u<<1,l,mid,pl,pr)+query(u<<1|1,mid+1,r,pl,pr);
	}
}tr;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(2,std::vector<char> (n+2));
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++) std::cin>>g[i][j];

    
    tr.build(1,1,n,g);

    std::vector<std::array<int,2>> h(n*2+2);
    for(int i=0,idx=1;i<2;i++){
        for(int j=1;j<=n;j++){
            h[idx++]={i,j};
        }
    }


    while(m--){
        int u,v;
        std::cin>>u>>v;
        if(h[u][1]>h[v][1]) std::swap(u,v);
        
        auto t=tr.query(1,1,n,h[u][1],h[v][1]).a;
        int res=t[h[u][0]>0][h[v][0]>0];
        if(res==inf) res=-1;
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
