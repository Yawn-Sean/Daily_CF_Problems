/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Descar_tree{
	std::stack<int> stk;
	std::vector<std::array<int,2>> tr;
    std::vector<int> L,R;
	int root=-1;
    Descar_tree(){};
    Descar_tree(int n,std::vector<int> &a){
        L.clear(),R.clear();
        L.resize(n+2),R.resize(n+2);
        tr.resize(n+2);root=-1;
        stk=std::stack<int>();
		for(int i=1;i<=n;i++){
			while(stk.size() and a[stk.top()]<a[i]) {
				tr[i][0]=stk.top(),stk.pop();
			}
			if(stk.size()) tr[stk.top()][1]=i;
			else root=i;
			stk.push(i);
		}
        dfs(root,-1);
    };
    void dfs(int u,int fa){
        auto &t=tr[u];
        L[u]=R[u]=u;
        if(t[0]){
            dfs(t[0],u);
            L[u]=std::min(L[u],L[t[0]]);
            R[u]=std::max(R[u],R[t[0]]);
        }
        if(t[1]){
            dfs(t[1],u);
            L[u]=std::min(L[u],L[t[1]]);
            R[u]=std::max(R[u],R[t[1]]);
        }
    };
};

constexpr int N=200010;

struct Info{
    int mi=2000000000;

    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.mi=std::min(a.mi,b.mi);
        return res;
    };
};

struct Segment_tree{
    Info info[N*4];
    int a[N];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            info[u].mi=a[l];
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
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

    int query(int u,int l,int r,int x){
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(info[u<<1].mi<x) return query(u<<1,l,mid,x);
        else return query(u<<1|1,mid+1,r,x);
    }
}tr;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    Descar_tree dt(n,a);

    std::vector<int> max_len(n+2);

    for(int i=1;i<=n;i++){
        if(a[i]<=n) max_len[a[i]]=std::max(max_len[a[i]],dt.R[i]-dt.L[i]+1);
    }

    for(int i=0;i<=n;i++) tr.a[i]=max_len[i];
    tr.build(1,0,n);
    for(int i=1;i<=n;i++) std::cout<<tr.query(1,0,n,i)<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
