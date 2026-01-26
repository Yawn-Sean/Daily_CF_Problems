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

using al2=array<LL,2>; // [days,cost]
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	LL n,k; cin>>n>>k;
	vector<al2>a; a.reserve(100);
	a.push_back({k+1,1});
	while(a.size()<k && a.back()[0]<n){
		const auto& [d,c]=a.back();
		a.push_back({d*k+1,c*k+1});
	}
	LL ans=0;
	if(a.size()==k && n>=a.back()[0]){
		ans=a.back()[1];
		n-=a.back()[0];
		ans+=n;
	}
	else{
		for(int i=int(a.size())-1;~i;--i){
			const auto& [d,c]=a[i];
			LL p=n/d;
			ans+=p*c;
			n-=p*d;
		}
	}
	cout<<ans;
	return 0;
}
