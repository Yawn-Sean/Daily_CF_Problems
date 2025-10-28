#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

#define ls (id<<1)
#define rs (id<<1|1)
class SGT{
private:
	struct Node{
		int l,r;
		int mn; bool tag;
		friend Node operator +(const Node& A,const Node& B){
			Node ret;
			ret.l=A.l,ret.r=B.r;
			ret.mn=max(A.mn,B.mn);
			ret.tag=0;
			return ret;
		}
	};
	vector<Node>q;
	void spread(int id){
		if(q[id].l==q[id].r) return;
		//spread the lazy tag
		if(q[id].tag){
			q[ls].mn=q[id].mn;
			q[rs].mn=q[id].mn;
			q[ls].tag=1;
			q[rs].tag=1;
			q[id].tag=0;
		}
	}
	void build(int l,int r,int id=1){
		if(l==r){
			q[id].l=l,q[id].r=r;
			q[id].mn=-1,q[id].tag=0;
			return;
		}
		int mid=l+r>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		q[id]=q[ls]+q[rs];
	}
public:
	SGT(int n){
		init(n);
	}
	void init(int n){
		q.resize(n*5);
		build(1,n);
	}
	void modify(int l,int r,int val,int id=1){
		if(q[id].l==l && q[id].r==r){
			q[id].mn=val,q[id].tag=1;
			return;
		}
		spread(id);
		int mid=q[id].l+q[id].r>>1;
		if(r<=mid) modify(l,r,val,ls);
		else if(l>mid) modify(l,r,val,rs);
		else modify(l,mid,val,ls),modify(mid+1,r,val,rs);
		q[id]=q[ls]+q[rs];
	}
	void to_ary(auto&& a,int id=1){
		if(q[id].l==q[id].r){
			a[q[id].l]=q[id].mn;
			return;
		}
		spread(id);
		to_ary(a,ls);
		to_ary(a,rs);
	}
//	int query(int l,int r,int id=1){
//		if(q[id].l==l && q[id].r==r) return q[id].mn;
//		spread(id);
//		int mid=q[id].l+q[id].r>>1;
//		if(r<=mid) return query(l,r,ls);
//		else if(l>mid) return query(l,r,rs);
//		return max(query(l,mid,ls),query(mid+1,r,rs));
//	}
//	int get(int pos,int id=1){
//		if(q[id].l==q[id].r) return q[id].mn;
//		spread(id);
//		int mid=q[id].l+q[id].r>>1;
//		if(pos<=mid) return get(pos,ls);
//		return get(pos,rs);
//	}
};
#undef ls
#undef rs

void solve(){
	int n,Q;
	cin>>n>>Q;
	vector<vector<int>>e(n+1);
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	constexpr int root=1;
	vector<int>dep(n+1),fa(n+1),siz(n+1),son(n+1);
	auto dfs1=[&](auto&& self,int u,int pre)->void{
		dep[u]=dep[pre]+1,fa[u]=pre,siz[u]=1;
		for(auto v:e[u]){
			if(v==pre) continue;
			self(self,v,u);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
	};
	dfs1(dfs1,root,0);
	vector<int>dfn(n+1),dfn_inv(n+1),top(n+1);
	int timStamp=0;
	auto dfs2=[&](auto&& self,int u,int t)->void{
		dfn[u]=++timStamp,dfn_inv[timStamp]=u,top[u]=t;
		if(!son[u]) return;
		self(self,son[u],t);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u]) continue;
			self(self,v,v);
		}
	};
	dfs2(dfs2,root,root);
	auto LCA=[&](int u,int v)->int{
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	};
	auto dis=[&](int u,int v)->int{
		return dep[u]+dep[v]-dep[LCA(u,v)]*2;
	};
	SGT sgt(n); // sgt needs to support seg add, seg query
	auto modify_path=[&](int u,int v,int val)->void{
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			sgt.modify(dfn[top[u]],dfn[u],val);
			u=fa[top[u]];
		}
		if(dep[u]<dep[v]) swap(u,v);
		sgt.modify(dfn[v],dfn[u],val);
	};
	vector<ai2>qry(Q+1);
	for(int i=1;i<=Q;++i){
		cin>>qry[i][0]>>qry[i][1];
	}
	for(int i=Q;i>0;--i){
		modify_path(qry[i][0],qry[i][1],i);
	}
	vector<int>ans(Q+1);
	vector<vector<int>>add;
	vector<int>dsu(n+1);
	vector<ai3>rt(n+1);
	auto get=[&](int x)->int{
		while(x!=dsu[x]){
			x=dsu[x]=dsu[dsu[x]];
		}
		return x;
	};
	vector<int>vis(n+1); int col=0;
	auto work=[&](const auto& o,int st,int ed,int delta)->void{
		add.assign(Q+1,{});
		for(int i=1;i<=n;++i){
			if(o[i]!=-1) add[o[i]].emplace_back(i);
		}
		for(int i=1;i<=n;++i){
			dsu[i]=i;
			rt[i]={0,i,i};
		}
		++col;
		int mxd=0;
		for(int t=st;;t+=delta){
			for(const auto& u:add[t]){
				vis[u]=col;
				for(const auto& v:e[u]){
					if(vis[v]!=col) continue;
					// merge u, v
					const int fau=get(u);
					const int fav=get(v);
					assert(fau!=fav);
					const ai3& ru=rt[fau];
					const ai3& rv=rt[fav];
					ai3 nr=max(ru,rv);
					for(int i=1;i<=2;++i){
						const int& x=ru[i];
						for(int j=1;j<=2;++j){
							const int& y=rv[j];
							ai3 nw={dis(x,y),x,y};
							updmx(nr,nw);
						}
					}
					dsu[fau]=fav;
					rt[fav]=nr;
					updmx(mxd,nr[0]);
				}
			}
			updmx(ans[t],mxd);
			if(t==ed) break;
		}
	};
	vector<int>tsg(n+1),tb(n+1),tw(n+1); // turn_black/white
	sgt.to_ary(tsg);
	for(int i=1;i<=n;++i){
		tb[i]=tsg[dfn[i]];
	}
	for(int i=1;i<=n;++i){
		if(tb[i]==-1) tw[i]=Q;
		else{
			tw[i]=tb[i]-1;
			if(tw[i]<=0) tw[i]=-1;
		}
	}
	dbg(tb);
	dbg(tw);
	dbg("nw tb");
	work(tb,1,Q,1);
	dbg("nw tw");
	work(tw,Q,1,-1);
	for(int i=1;i<=Q;++i){
		cout<<(ans[i]+1)<<'\n';
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
