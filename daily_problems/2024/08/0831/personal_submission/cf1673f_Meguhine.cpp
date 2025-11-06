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

constexpr int N=32;
constexpr int M=N*N;
int a[N][N],g[N];
ai2 pos[M];

int G(int n){return n^(n>>1);}
void init(){
	for(int i=0;i<N;++i){
		g[i]=G(i);
		int x=0;
		for(int j=0;j<5;++j){
			x|=((g[i]>>j)&1)<<(j*2);
		}
		g[i]=x;
	}
	LL tot_cost=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			a[i][j]=(g[i]<<1)|g[j];
#ifdef LOCAL
			cerr<<setfill(' ')<<setw(4)<<a[i][j]<<" \n"[j==N-1];
#endif
			pos[a[i][j]]={i+1,j+1};
			if(i) tot_cost+=a[i][j]^a[i-1][j];
			if(j) tot_cost+=a[i][j]^a[i][j-1];
		}
	}
	dbg(tot_cost);
	assert(tot_cost<=48000);
}

int main(){
	init();
	int n,Q;
	cin>>n>>Q;
	for(int i=0;i<n;++i){ // lr
		for(int j=1;j<n;++j){
			int x=a[i][j]^a[i][j-1];
			cout<<x<<' ';
		}
		cout<<'\n';
	}
	for(int i=1;i<n;++i){ // ud
		for(int j=0;j<n;++j){
			int x=a[i][j]^a[i-1][j];
			cout<<x<<' ';
		}
		cout<<'\n';
	}
	cout<<flush;
	for(int x=0,y;Q--;){
		cin>>y;
		x^=y;
		cout<<pos[x][0]<<' '<<pos[x][1]<<endl;
	}
	return 0;
}
