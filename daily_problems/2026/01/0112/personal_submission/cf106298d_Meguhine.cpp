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

constexpr int N=1e6+5;
bitset<N>notP; int phi[N],mn_p[N];
vector<int>prime;
void init_prime(const int n=N){ // init [1,n-1]
	phi[1]=mn_p[1]=notP[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
			phi[i]=i-1;
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			notP[i*p]=1,mn_p[i*p]=p;
			if(i%p==0){
				phi[i*p]=phi[i]*p;
				break;
			}
			phi[i*p]=phi[i]*(p-1);
		}
	}
}

#define FAIL {cout<<"NO\n";return;}
void solve(){
	int n; cin>>n;
	vector<ai2>a(n);
	vector<int>ans(n);
	auto check=[&](const int x)->bool {
		for(int i=0;i<n;++i){
			const auto& [l,r]=a[i];
			const int y=((l-1)/x+1)*x;
			if(y>r) return 0;
			ans[i]=y;
		}
		cout<<"YES\n";
		for(auto y:ans) cout<<y<<' ';
		cout<<'\n';
		return 1;
	};
	for(auto& [x,_]:a) cin>>x;
	int g=0;
	for(auto& [l,r]:a){
		cin>>r;
		if(l==r) g=gcd(g,l);
	}
	if(g==1) FAIL;
	if(!g || g%2==0){
		assert(check(2));
		return;
	}
	vector<int>d;
	while(g!=1){
		const int p=mn_p[g];
		d.emplace_back(p);
		while(g%p==0) g/=p;
	}
	for(auto x:d){
		if(check(x)) return;
	}
	FAIL;
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
