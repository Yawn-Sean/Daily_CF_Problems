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

#define N 30000
#define MM 15

int n,deg[N],opt[N][MM];

int main(){
	scanf("%d",&n);
	printf("QUERY ");
	for(int i=0;i<n;++i) printf("1");
	cout<<endl;
	for(int i=0;i<n;++i) scanf("%d",&deg[i]);
	const int M=__lg(n-1);
	for(int p=0;p<=M;++p){
		printf("QUERY ");
		for(int i=0;i<n;++i) printf("%d",i>>p&1);
		cout<<endl;
		for(int i=0;i<n;++i){
			scanf("%d",&opt[i][p]);
		}
	}
	queue<int>p;
	for(int i=0;i<n;++i){
		if(deg[i]==1) p.push(i);
	}
	printf("ANSWER\n");
	for(int $=1;$<n;++$){
		int u=p.front();
		p.pop();
		int v=0;
		for(int i=0;i<=M;++i){
			if(opt[u][i]) v|=1<<i;
		}
		for(int i=0;i<=M;++i){
			if(u>>i&1) --opt[v][i];
		}
		if(--deg[v]==1) p.push(v);
		printf("%d %d\n",u+1,v+1);
	}
	return 0;
}
