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

/*
let d[0] be virtual S, d[0]=0.
graph is 1-based-index.
d[x]-d[y]<=c : addineq(x,y,c)
d[x]-d[y]>=c : addineq(y,x,-c)
d[x]-d[y]==c : addineq(x,y,c), addineq(y,x,-c)
d[x]==d[y] : addineq(x,y,0), addineq(y,x,0)
default: -hinf<=d[x]<=hinf
if, l<=d[x]<=r:
- d[x]-d[0]>=l, addineq(0,x,-l)
- d[x]-d[0]<=r, addineq(x,0,r)
*/
constexpr LL inf=2e18;
constexpr LL hinf=inf/2; // half inf
struct DC{ // diff-constraints
	int n;
	vector<bool>vis;
	vector<int>cnt;
	vector<LL>dis,L,R;
	vector<vector<pair<int,LL>>>e;
	DC(){}
	DC(int n_){init(n_);}
	void init(int n_){
		n=n_;
		L.assign(n+1,-hinf);
		R.assign(n+1,hinf);
		e.assign(n+1,{});
	}
	void addineq(int x,int y,LL c){ // d[x]-d[y]<=c
		e[y].emplace_back(x,c);
	}
	void setx(int x,LL l,LL r){ // l<=x<=r
		L[x]=l,R[x]=r;
	}
	bool spfa(){
		vis.assign(n+1,0);
		cnt.assign(n+1,0);
		dis.assign(n+1,inf);
		dis[0]=0,vis[0]=1;
		queue<int>p; p.push(0);
		while(p.size()){
			int u=p.front();
			p.pop(),vis[u]=0;
			for(auto& [v,w]:e[u]){
				if(updmn(dis[v],dis[u]+w)){
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n+1) return 0;
					if(!vis[v]) p.push(v),vis[v]=1;
				}
			}
		}
		return 1;
	}
	bool check(){
		for(int i=1;i<=n;++i){
			addineq(0,i,-L[i]);
			addineq(i,0,R[i]);
		}
		return spfa();
	}
};

/*
binary search
l,r,x,y:
x <= s[r]-s[l-1] <= y
s[i] = s[i-1]+a[i]+[-min(K,a[i]-1),K]
-min(K,a[i]-1) <= s[i]-(s[i-1]+a[i]) <= K
a[i]-min(K,a[i]-1) <= s[i]-s[i-1] <= a[i]+K
so... diff constraints
*/
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<tuple<int,int,LL,LL>>b(m);
	for(int i=0;i<m;++i){
		int l,r; LL x,y;
		cin>>l>>r>>x>>y;
		b[i]={l,r,x,y};
	}
	DC dc;
	auto addineq=[&](int i,int j,LL x,LL y)->void{
		// x <= s[j]-s[i] <= y
		if(!i) dc.setx(j,x,y);
		else{
			dc.addineq(j,i,y);
			dc.addineq(i,j,-x);
		}
	};
	auto check=[&](const LL& lim)->bool{
		dc.init(n);
		for(auto& [l,r,x,y]:b){
			addineq(r,l-1,x,y);
		}
		for(int i=1;i<=n;++i){
			addineq(i,i-1,-min(lim,(LL)a[i]-1)+a[i],lim+a[i]);
		}
		return dc.check();
	};
	LL l=0,r=1e16,mid,opt=-1;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			opt=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<opt;
	return 0;
}
