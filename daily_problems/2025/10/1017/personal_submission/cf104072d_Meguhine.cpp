#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
#include<bits/stdc++.h>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

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
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector a(n,vector<int>(n));
	for(auto& v:a) for(auto& x:v) cin>>x;
	vector U(n,vector<int>(n));
	vector D(n,vector<int>(n));
	vector L(n,vector<int>(n));
	vector R(n,vector<int>(n));
	vector ul(n,vector<int>(n));
	vector dr(n,vector<int>(n));
	LL ans=0;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j){
		if(!a[i][j]) continue;
		U[i][j]=i?U[i-1][j]+1:1;
		L[i][j]=j?L[i][j-1]+1:1;
		++ans;
	}
	for(int i=n-1;~i;--i) for(int j=n-1;~j;--j){
		if(!a[i][j]) continue;
		D[i][j]=i!=n-1?D[i+1][j]+1:1;
		R[i][j]=j!=n-1?R[i][j+1]+1:1;
	}
	for(int i=0;i<n;++i) for(int j=0;j<n;++j){
		ul[i][j]=min(U[i][j],L[i][j]);
		dr[i][j]=min(D[i][j],R[i][j]);
	}
	dbg(ul);
	dbg(dr);
	auto work=[&](int sx,int sy){
		int i=sx,j=sy,k=0;
		vector<ai3>data;
		while(i<n && j<n){
			if(a[i][j]){
				dbg((ai3{k,k-ul[i][j]+1,0}));
				dbg((ai3{k+dr[i][j],k+1,1}));
				data.push_back(ai3{k,k-ul[i][j]+1,0});
				data.push_back(ai3{k+dr[i][j],k+1,1});
			}
			++i,++j,++k;
		}
		sort(all(data));
		dbg(data);
		fenwick_tree<int>fen(n+1);
		const int cc=data.size()/2;
		LL res=-cc*(cc+1)/2;
		for(auto& [x,y,_]:data){
			if(_) res+=fen.sum(0,y);
			else fen.add(y,1);
		}
		ans+=res;
	};
	work(0,0);
	for(int i=1;i<n;++i){
		work(i,0);
		work(0,i);
	}
	cout<<ans;
	return 0;
}
