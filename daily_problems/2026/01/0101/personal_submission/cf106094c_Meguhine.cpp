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

constexpr int N=2e5+5;
bitset<N>notP; int mn_p[N];
vector<int>prime;
void init_prime(const int& n=N){ // init [1,n-1]
	mn_p[1]=notP[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			notP[i*p]=1,mn_p[i*p]=p;
			if(i%p==0){
				break;
			}
		}
	}
}

void solve(){
	LL K; vector<int>d;
	{
		int x;
		cin>>x>>K;
		while(1){
			const int p=mn_p[x];
			if(p==1) break;
			int cc=0;
			while(x%p==0) x/=p,++cc;
			d.emplace_back(cc);
		}
	}
	LL x=1ll<<59;
	for(int i=59;~i;--i,x>>=1){
		LL res=0;
		for(auto c:d){
			LL tmp=c%x;
			if(tmp) res+=x-tmp;
		}
		if(res<=K){
			cout<<i<<'\n';
			return;
		}
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init_prime();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
