/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;

int n,k,a,b,q;

struct Info{//information
	int sa=0,sb=0;

	Info() {};
	friend Info operator + (const Info &a,const Info &b){
		Info res;
		res.sa=a.sa+b.sa;
        res.sb=a.sb+b.sb;

		return res;
	};
};

struct Segment_tree{
	Info info[N*4];
	
	void pushup(int u){
		info[u]=info[u<<1]+info[u<<1|1];
	}
	
	
	void build(int u,int l,int r){
		if(l==r) {
			info[u].sa=0,info[u].sb=0;
		}else{
			int mid=(l+r)>>1;
			build(u<<1,l,mid);
			build(u<<1|1,mid+1,r);
			pushup(u);
		}
	}
	
	void modify(int u,int l,int r,int pl,int pr,int c){
		if(l>=pl and r<=pr) {
			info[u].sa=std::min(info[u].sa+c,a);
            info[u].sb=std::min(info[u].sb+c,b);
			return;
		}
		int mid=(l+r)>>1;
		if(pl<=mid) modify(u<<1,l,mid,pl,pr,c);
		if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,c);
		pushup(u);
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
    std::cin>>n>>k>>a>>b>>q;

    tr.build(1,1,n);

    while(q--){
        int op;
        std::cin>>op;
        if(op==1){
            int x,c;
            std::cin>>x>>c;
            tr.modify(1,1,n,x,x,c);
        }else{
            int x;
            std::cin>>x;
            int res=0;
            if(x>1) res+=tr.query(1,1,n,1,x-1).sb;
            if(x<n) res+=tr.query(1,1,n,x+k,n).sa;
            std::cout<<res<<"\n";
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
