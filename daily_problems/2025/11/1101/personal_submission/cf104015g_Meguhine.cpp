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

#define N 200005
int n,buca[N],bucb[N];
ai2 a[N];
LL ans=0;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	cin>>n;
	for(int i=1;i<=n;++i){ // no a[i]==a[j] && b[i]==b[j]
		cin>>a[i][0]>>a[i][1];
		++buca[a[i][0]];
		++bucb[a[i][1]];
	}
	{ // add a not same
		LL s=0,s2=0;
		for(int i=1;i<N;++i){
			ans+=s2*buca[i];
			s2+=s*buca[i];
			s+=buca[i];
		}
	}
	{ // add b not same
		LL s=0,s2=0;
		for(int i=1;i<N;++i){
			ans+=s2*bucb[i];
			s2+=s*bucb[i];
			s+=bucb[i];
		}
	}
	dbg(ans);
	/*
	sub SUB := #(a,b both not same)
	SUB=ALL -#(>=1 elem have ==2 same) -#(>=1 elem are same)
		ALL -#(as have ==2 same) -#(bs have ==2 same) +#(as,bs both have ==2 same)
		-#(as are same) -#(bs are same) +#(as,bs are same)
	*/
	LL SUB=1ll*n*(n-1)*(n-2)/6; // ALL
	dbg("ALL",SUB);
	{ // -#(as have ==2 same)
		LL s=0;
		for(int x=1;x<N;++x){
			const int& c=buca[x];
			if(!c) continue;
			s+=1ll*c*(c-1)/2*(n-c);
		}
		SUB-=s;
		dbg(s);
	}
	{ // -#(bs have ==2 same)
		LL s=0;
		for(int x=1;x<N;++x){
			const int& c=bucb[x];
			if(!c) continue;
			s+=1ll*c*(c-1)/2*(n-c);
		}
		SUB-=s;
		dbg(s);
	}
	{ // +#(as,bs both have ==2 same)
		for(int i=1;i<=n;++i){
			const auto& [x,y]=a[i];
			SUB+=1ll*(buca[x]-1)*(bucb[y]-1);
		}
	}
	{ // -#(as are same)
		for(int x=1;x<N;++x){
			const int& y=buca[x];
			if(y<=2) continue;
			SUB-=1ll*y*(y-1)*(y-2)/6;
		}
	}
	{ // -#(bs are same)
		for(int x=1;x<N;++x){
			const int& y=bucb[x];
			if(y<=2) continue;
			SUB-=1ll*y*(y-1)*(y-2)/6;
		}
	}
	// +#(as,bs are same), which is 0
	dbg(SUB);
	ans-=SUB;
	cout<<ans;
	return 0;
}
