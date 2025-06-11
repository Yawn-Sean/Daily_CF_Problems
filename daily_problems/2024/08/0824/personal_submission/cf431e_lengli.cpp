/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

struct Info{//information
	long long v=0,cnt=0;
	Info(){}
	friend Info operator + (const Info &a,const Info &b){
		Info res;
		res.v=a.v+b.v;
        res.cnt=a.cnt+b.cnt;
		return res;
	};
};

struct Segment_tree{
	std::vector<Info> info;
	std::vector<int> ls,rs;
	int idx=-1,root;
	
	int getnode(int l,int r,int v){
		idx++;
		info.push_back(Info());
		ls.push_back(-1),rs.push_back(-1);
		return idx;
	}
	
	void pushup(int u){
		info[u]=info[ls[u]]+info[rs[u]];
	}
	
	void pushdown(int u,int l,int r){
		if(ls[u]==-1){
			int t=getnode(l,(l+r)/2,0);
			ls[u]=t;
		}
		if(rs[u]==-1){
			int t=getnode((l+r)/2+1,r,0);
			rs[u]=t;
		}
	}
	
	void modify(int u,int l,int r,int pl,int pr,const int &t){
		if(l>=pl and r<=pr) {
			info[u].cnt+=t;
            info[u].v=1ll*info[u].cnt*l;
			return;
		}
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(pl<=mid) modify(ls[u],l,mid,pl,pr,t);
		if(pr>mid) modify(rs[u],mid+1,r,pl,pr,t);
		pushup(u);
	}
	
	void init(){
		root=getnode(0,inf,0);
	}
	
	Info query(int u,int l,int r,int pl,int pr){
		if(l>=pl and r<=pr) return info[u];
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(pl>mid) return query(rs[u],mid+1,r,pl,pr);
		else if(pr<=mid) return query(ls[u],l,mid,pl,pr);
		else return query(ls[u],l,mid,pl,pr)+query(rs[u],mid+1,r,pl,pr);
	}
}tr;

void solve(){
    int n,m;
    std::cin>>n>>m;
    tr.init();
    std::vector<int> h(n+2);
    for(int i=1;i<=n;i++) std::cin>>h[i];
    for(int i=1;i<=n;i++) tr.modify(0,0,inf,h[i],h[i],1);
    for(int i=1;i<=m;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int x,v;
            std::cin>>x>>v;
            tr.modify(0,0,inf,h[x],h[x],-1);
            h[x]=v;
            tr.modify(0,0,inf,h[x],h[x],1);
        }else{
            long long k;
            std::cin>>k;
            int l=1,r=inf;

            auto check=[&](int x){
                auto t=tr.query(0,0,inf,0,x-1);
                long long ma=t.cnt*x;
                if(ma-t.v>=k) return 1;
                return 0;
            };

            while(l<r){
                int mid=(l+r)>>1;
                if(check(mid)) r=mid;
                else l=mid+1;
            }

            auto t=tr.query(0,0,inf,0,r-1);
            double res=t.v+k;
            res/=(double)t.cnt;
            std::cout<<std::fixed<<std::setprecision(5)<<res<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
