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
template<class T>inline voaid clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

constexpr int N=305;
int a[N][N],b[N][N*N];  // len is k, r is x, l_mx is b[k][x] 

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	memset(b,0xff,sizeof(b));
	int n,Q;
	cin>>n>>Q;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			const int ij=max(i,j);
			for(int k=1;ij+k-1<n;++k){
				const int mx=a[i+k-1][j+k-1];
				updmx(b[k][mx],a[i][j]);
			}
		}
	}
	for(int len=1;len<=n;++len){
		for(int mx=1;mx<N*N;++mx){
			updmx(b[len][mx],b[len][mx-1]);
		}
	}
	for(int l,r;Q--;){
		cin>>l>>r;
		int ans=0;
		for(int len=n;len>0;--len){
			if(b[len][r]>=l){
				ans=len;
				break;
			}
		}
		cout<<(ans*ans)<<'\n';
	}
	return 0;
}
