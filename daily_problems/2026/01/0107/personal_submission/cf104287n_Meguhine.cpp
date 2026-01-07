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
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

using pil=pair<int,LL>;
bool cmp(const pil& x,const pil& y){
	return x.second>y.second;
}

void solve(){
	int n; cin>>n;
	vector<vector<pil>>e(n+1);
	for(int i=1,u,v,w;i<n;++i){
		cin>>u>>v>>w;
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	if(n<=3){
		cout<<"0\n";
		return;
	} 
	vector<LL>f(n+1),dp(n+1);
	vector<vector<pil>>mx(n+1);
	auto dfs=[&](auto&& self,int u,int fa)->void {
		mx[u].reserve(3);
		for(auto [v,w]:e[u]){
			if(v==fa) continue;
			self(self,v,u);
			mx[u].emplace_back(v,f[v]+w);
			sort(all(mx[u]),cmp);
			if(mx[u].size()==4) mx[u].pop_back();
		}
		if(mx[u].size()){
			dp[u]=f[u]=mx[u][0].second;
			if(mx[u].size()>1) dp[u]+=mx[u][1].second;
		}
	};
	dfs(dfs,1,0);
	LL ans=0;
	auto dfs2=[&](auto&& self,int u,int fa,const LL f_fa,const LL dp_fa)->void {
		vector<pil>nw=mx[u];
		nw.emplace_back(fa,f_fa);
		sort(all(nw),cmp);
		if(nw.size()==4) nw.pop_back();
		for(auto [v,w]:e[u]){
			if(v==fa) continue;
			LL res=0,fnw=0;
			for(int i=0,j=0;i<(int)(nw.size());++i){
				if(nw[i].first==v) continue;
				updmx(fnw,nw[i].second);
				res+=nw[i].second;
				if(++j==2) break;
			}
			updmx(res,dp_fa);
			dbg(u,v,res,dp[v]);
			updmx(ans,min(res,dp[v]));
			self(self,v,u,fnw+w,res);
		}
	};
	dfs2(dfs2,1,0,0,0);
	cout<<ans<<'\n';
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
