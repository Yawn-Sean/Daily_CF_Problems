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

/*
feature of snake:
- no 2x2
- no 1x3, 3x1
*/

constexpr auto dir=make_tuple(
	array<ai2,3>{
		ai2{0,1},{1,0},{1,1}
	},
	array<ai2,2>{
		ai2{0,1},{0,2}
	},
	array<ai2,2>{
		ai2{1,0},{2,0}
	}
);

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m; cin>>n>>m;
	vector a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	auto update=[&]<int d>(auto&& b,const int i,const int j)->void {
		for(const auto [di,dj]:get<d>(dir)){
			const int ni=i+di;
			const int nj=j+dj;
			if(ni>n || nj>m) return;
			if(a[i][j]!=a[ni][nj]) return;
		}
		b[i][j]=1;
	};
	auto work=[&]<int d>(auto&& b)->void {
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				update.operator()<d>(b,i,j);
				b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
			}
		}
	};
	auto check=[&](auto&& b,int sx,int sy,int tx,int ty)->bool {
		if(sx<=tx && sy<=ty){
			return !!(b[tx][ty]-b[sx-1][ty]-b[tx][sy-1]+b[sx-1][sy-1]);
		}
		else return 0;
	};
	vector b(n+1,vector<int>(m+1));  // for 2x2
	vector c(n+1,vector<int>(m+1));  // for 1x3
	vector d(n+1,vector<int>(m+1));  // for 3x1
	work.operator()<0>(b);
	work.operator()<1>(c);
	work.operator()<2>(d);
	int Q; cin>>Q;
	for(int sx,sy,tx,ty;Q--;){
		cin>>sx>>sy>>tx>>ty;
		++sx,++sy,++tx,++ty;
		if(check(b,sx,sy,tx-1,ty-1) ||
		check(c,sx,sy,tx,ty-2) ||
		check(d,sx,sy,tx-2,ty)){
			cout<<"NO\n";
		}
		else cout<<"YES\n";
	}
	return 0;
}
