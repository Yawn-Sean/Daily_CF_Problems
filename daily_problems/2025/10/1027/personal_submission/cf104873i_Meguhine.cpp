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

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>>a(n);
	auto ask=[&](int l,int r)->void{
		printf("? %d",(r-l+1)*2);
		for(int i=l;i<=r;++i) printf(" %d %d",i,i);
		printf("\n"); fflush(stdout);
		int m; scanf("%d",&m);
		vector<int>b(m);
		for(auto& x:b) scanf("%d",&x);
		int j=0,k;
		for(int i=l-1;i<r;++i){
			for(k=j+1;b[j]!=b[k];++k);
			a[i]={b.begin()+j,b.begin()+k};
			j+=(k-j)*2;
		}
	};
	if(n==1){
		printf("? 1 1\n"); fflush(stdout);
		int x; scanf("%d",&x);
		a[0].resize(x);
		for(auto& y:a[0]) scanf("%d",&y);
	}
	else{
		const int m=n/2;
		ask(1,m);
		ask(m+1,m*2);
		if(n&1) ask(m*2+1,n);
	}
	printf("!");
	for(auto& v:a){
		printf(" %llu",v.size());
		for(auto& x:v) printf(" %d",x);
	}
	return 0;
}
