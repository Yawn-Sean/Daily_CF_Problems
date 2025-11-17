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

int ask(int n,int d){
	cout<<"?";
	for(int _=0;_<2;++_){
		printf(" %d",n-(!!d));
		for(int i=1;i<=n;++i){
			if(i!=d) printf(" %d",i);
		}
	}
	cout<<endl;
	int x; cin>>x;
	return x;
}
#define FUCK(x) {cout<<"! "<<(int)(x)<<endl;return;}
void solve(){
	int n; cin>>n;
	int m=ask(n,0);
	int s=0;
	for(int i=1;i<n;++i){
		int x=ask(n,i);
		s+=m-x;
		if(x+1==m) FUCK(i);
	}
	if(m*2-s==1) FUCK(n);
	FUCK(-1);
}
int main(){
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
