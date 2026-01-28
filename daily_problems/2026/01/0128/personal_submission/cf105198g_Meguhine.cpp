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

// for 3x3
int opt[3][3];
bool check(){
	for(int i=0;i<3;++i){
		int r=0;
		for(int j=0;j<3;++j){
			r+=opt[i][j];
		}
		if(r!=(1<<__lg(r))) return 0;
	}
	for(int i=0;i<3;++i){
		int r=0;
		for(int j=0;j<3;++j){
			r+=opt[j][i];
		}
		if(r!=(1<<__lg(r))) return 0;
	}
	{
		int r=0;
		for(int i=0;i<3;++i){
			r+=opt[i][i];
		}
		if(r!=(1<<__lg(r))) return 0;
	}
	{
		int r=0;
		for(int i=0;i<3;++i){
			r+=opt[i][2-i];
		}
		if(r!=(1<<__lg(r))) return 0;
	}
	return 1;
}
bool dfs(int i,int j){
	if(i==3){
		return check();
	}
	int ni=i,nj=j;
	if(++nj==3){
		nj=0;
		++ni;
	}
	for(int x=1;x<=8;++x){
		opt[i][j]=x;
		if(dfs(ni,nj)) return 1;
	}
	return 0;
}

constexpr int N=1005;
int a[N][N];

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	assert(dfs(0,0));
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=1;
		}
	}
	if(n>=4){
		const int lg=__lg(n);
		if(n!=(1<<lg)){
			const int x=(1<<(lg+1))-n;
			a[1][1]+=x;
			a[2][n-1]+=x;
			a[3][n]+=x;
			if(n&1){
				for(int r=n,c=2;c<n-1;--r,++c){
					a[r][c]+=x;
				}
			}
			else{
				for(int r=4,c=2;c<n-1;++r,++c){
					a[r][c]+=x;
				}
			}
		}
	}
	else if(n==3){
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j){
				a[i][j]=opt[i-1][j-1];
			}
		}
	}
	else{
		// n==1 or n==2 already ok.
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<" \n"[j==n];
		}
	}
	return 0;
}
