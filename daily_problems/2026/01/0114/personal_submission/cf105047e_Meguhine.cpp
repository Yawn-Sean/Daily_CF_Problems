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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<ai2>ans; ans.reserve(2500);
	auto myswap=[&](int l,int r)->void {
		assert(!a[l] || !a[r]);
		if(!a[l]){
			ans.push_back({l,r});
			ans.push_back({r,l});
		}
		else{
			ans.push_back({r,l});
			ans.push_back({l,r});
		}
		swap(a[l],a[r]);
	};
	{
		vector<int>v; v.reserve(21);
		for(int s=1;s<(1<<21);++s){
			int r=0; v.clear();
			for(int i=0;i<=20;++i) if(s>>i&1){
				r^=a[i+1];
				v.emplace_back(i+1);
			}
			if(!r){
				const int p=v[0];
				for(int i=1;i<(int)(v.size());++i){
					a[p]^=a[v[i]];
					ans.push_back({p,v[i]});
				}
				assert(!a[p]);
				if(p!=1) myswap(1,p);
				assert(!a[1]);
				break;
			}
		}
	}
	dbg("make a[1] zero",ans.size());
	vector<int>to(n+1);
	{
		vector<int>b=a; sort(all(b));
		unordered_map<int,queue<int>>sorted_pos;
		for(int i=1;i<=n;++i){
			sorted_pos[b[i]].push(i);
		}
		for(int i=1;i<=n;++i){
			const int x=a[i];
			to[i]=sorted_pos[x].front();
			sorted_pos[x].pop();
		}
	}
	#ifdef LOCAL
	{
		vector<int>c(n+1);
		for(int i=1;i<=n;++i){
			c[to[i]]=a[i];
		}
		dbg(is_sorted(all(c)));
		assert(is_sorted(all(c)));
	}
	#endif
	vector<bool>vis(n+1);
	vector<int>p; p.reserve(n+1);
	auto work=[&](const int st)->void {
		p.clear();
		{
			int u=st;
			while(!vis[u]){
				p.emplace_back(u);
				vis[u]=1;
				u=to[u];
			}
		}
		if(p.size()==1) return;
		if(p.size()==2){
			ans.push_back({p[0],p[1]});
			a[p[0]]^=a[p[1]];
			ans.push_back({p[1],p[0]});
			a[p[1]]^=a[p[0]];
			ans.push_back({p[0],p[1]});
			a[p[0]]^=a[p[1]];
			return;
		}
		myswap(1,p[0]);
		int pos_zero=p[0];
		p[0]=1;
		for(int i=(int)(p.size())-1;~i;--i){
			myswap(pos_zero,p[i]);
			pos_zero=p[i];
		}
	};
	for(int i=2;i<=n;++i){
		if(!vis[i]) work(i);
	}
	assert(is_sorted(all(a)));
	assert(ans.size()<=2500);
	cout<<ans.size()<<'\n';
	for(auto& [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}
