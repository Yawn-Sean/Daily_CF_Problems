/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct FHQ_number
{
	#define Maxn 100010
	#define ls tree[p].pl
	#define rs tree[p].pr
    #define ll long long
	private:
		int All=0,root=0;
		struct NODE { int pl,pr,siz,cnt,rnd; ll val; };
		NODE tree[Maxn];
		inline int Dot() { return ++All; }
		inline int New(ll Val)
		{
			int p=Dot();
			tree[p].rnd=rand(),tree[p].val=Val;
			tree[p].siz=tree[p].cnt=1;
			tree[p].pl=tree[p].pr=0;
			return p;
		}
		inline void pushdown(int p) { p--; }
		inline void pushup(int p)
			{ tree[p].siz=tree[ls].siz+tree[rs].siz+tree[p].cnt; }
		void split(int p,int k,int &x,int &y)
		{
			if(!p) { x=y=0; return; }
			pushdown(p);
			if(tree[p].val<=k) x=p,split(rs,k,rs,y);
			else y=p,split(ls,k,x,ls);
			pushup(p);
		}
		int merge(int x,int y)
		{
			if(!x || !y) return x+y;
			if(tree[x].rnd<tree[y].rnd)
			{
				pushdown(x),tree[x].pr=merge(tree[x].pr,y),pushup(x);
				return x;
			}
			else
			{
				pushdown(y),tree[y].pl=merge(x,tree[y].pl),pushup(y);
				return y;
			}
		}
		inline int kth(int p,int Rank)
		{
			while(p)
			{
				if(tree[ls].siz>=Rank) p=ls;
				else if(tree[ls].siz+tree[p].cnt>=Rank) return p;
				else Rank-=tree[ls].siz+tree[p].cnt,p=rs;
			}
			return p;
		}
		int x,y,z;
	public:
		inline void Insert(ll Val)
			{ split(root,Val,x,y),root=merge(merge(x,New(Val)),y); }
		inline void Delete_one(int Val)
		{
			split(root,Val,x,z),split(x,Val-1,x,y);
			y=merge(tree[y].pl,tree[y].pr);
			root=merge(merge(x,y),z);
		}
		inline ll Rank_to_Value(int Rank)
			{ return tree[kth(root,Rank)].val; }
		inline int Value_to_Rank(ll Value)
		{
			split(root,Value-1,x,y);
			int ret=tree[x].siz+1;
			root=merge(x,y);
			return ret;
		}
		inline ll Findpre(ll Value)
		{
			split(root,Value-1,x,y);
			ll ret=tree[kth(x,tree[x].siz)].val;
			root=merge(x,y);
			return ret;
		}
		inline ll Findnex(ll Value)
		{
			split(root,Value,x,y);
			ll ret=tree[kth(y,1)].val;
			root=merge(x,y);
			return ret;
		}
}tr;

void solve(){
    int n;
    std::cin>>n;
    int root=-1;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> c(n+2);
    for(int i=1;i<=n;i++){
        int p;
        std::cin>>p>>c[i];
        if(!p) root=i;
        else{
            eg[p].pb(i);
            eg[i].pb(p);
        }
    }

    bool flag=1;
    std::vector<int> res(n+2),sz(n+2);
    for(int i=1;i<=n;i++) tr.Insert(i);

    auto dfs=[&](auto self,int u,int fa)->void{
        sz[u]=1;
        res[u]=tr.Rank_to_Value(c[u]+1);
        if(!res[u]) flag=0;
        else tr.Delete_one(res[u]);
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            sz[u]+=sz[x];
        }
        if(sz[u]-1<c[u]) flag=0;
    };

    dfs(dfs,root,0);

    if(!flag) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
