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
0: 6
1: 2
2: 5
3: 5
4: 4
5: 5
6: 6
7: 3
8: 7
9: 6

useful:
  1: 2
  7: 3
  4: 4
  2: 5
0,6: 6
  8: 7
*/

constexpr ai10 costd={
	6,2,5,5,4,5,6,3,7,6
};

constexpr int N=1e6+5;
int dp[N];  // x segs -> dp[x]-digit
bool init_dp=[](){
	dp[0]=dp[1]=-1;
	for(int i=2;i<=7;++i) dp[i]=1;
	for(int l=8,x=2;l<N;l+=7,++x){
		for(int i=0;i<7;++i){
			if(l+i<N) dp[l+i]=x;
		}
	}
	return true;
}();

void solve(){
	int n; cin>>n;
	bool f=1;
	while(n>7){
		for(int i=f;i<10;++i){
			if(n>=costd[i] && dp[n-costd[i]]!=dp[n]){
				cout<<i;
				n-=costd[i];
				break;
			}
		}
		f=0;
	}
	for(int i=0;i<10;++i){
		if(costd[i]==n){
			cout<<i<<'\n';
			return;
		}
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
