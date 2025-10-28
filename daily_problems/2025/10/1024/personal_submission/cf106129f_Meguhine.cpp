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
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	vector<string>s(n);
	for(auto& t:s) cin>>t;
	auto check=[&](int l)->bool{
		vector a(n,vector<int>(m));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(s[i][j]!='#' || a[i][j]){
					continue;
				}
				for(int x=0;x<l;++x){
					const int ix=i+x;
					if(ix>=n) return 0;
					for(int y=0;y<l;++y){
						const int jy=j+y;
						if(jy>=m) return 0;
						if(s[ix][jy]!='#' || a[ix][jy]){
							return 0;
						}
						a[ix][jy]=1;
					}
				}
			}
		}
		return 1;
	};
	int g=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;){
			if(s[i][j]!='#'){
				++j;
				continue;
			}
			int k=j;
			for(;k<m && s[i][k]=='#';++k);
			g=gcd(g,k-j);
			j=k;
		}
	}
	for(int j=0;j<m;++j){
		for(int i=0;i<n;){
			if(s[i][j]!='#'){
				++i;
				continue;
			}
			int k=i;
			for(;k<n && s[k][j]=='#';++k);
			g=gcd(g,k-i);
			i=k;
		}
	}
	for(int l=g;l>1;--l){
		if(g%l) continue;
		if(check(l)){
			cout<<l;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
