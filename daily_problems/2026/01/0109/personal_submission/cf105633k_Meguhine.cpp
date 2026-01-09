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

constexpr int N=2e5+5;
constexpr int M=20;
int a[N];
int dp[1<<M][2];  // dp[s]={c,i} there are c bits other than s is covered; index i.

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m; cin>>n>>m;
	const int full=(1<<m)-1;
	vector<int>pos_full;
	ai2 mx_single={-1,0};
	for(int i=1;i<=n;++i){
		string s; cin>>s;
		int x=0;
		for(int j=0;j<m;++j){
			if(s[j]=='Y') x|=1<<j;
		}
		dbg(i,x);
		a[i]=x;
		if(x==full) pos_full.emplace_back(i);
		else{
			dp[x][0]=0,dp[x][1]=i;
			const int c=__builtin_popcount(x);
			if(mx_single[0]<c){
				mx_single={c,i};
			}
		}
	}
	if(pos_full.size()>=2){
		cout<<pos_full[0]<<' '<<pos_full[1];
		return 0;
	}
	if(pos_full.size()==1){
		int x=pos_full[0];
		int y=mx_single[1];
		if(x>y) swap(x,y);
		cout<<x<<' '<<y;
		return 0;
	}
	for(int s=full;~s;--s){
		dbg(s,dp[s][0],dp[s][1]);
		if(!dp[s][1]) continue;
		for(int i=0;i<m;++i) if(s>>i&1){
			int ns=s^(1<<i);
			if(dp[ns][0]<dp[s][0]+1 || (dp[ns][0]==dp[s][0]+1 && dp[ns][1]>dp[s][1])){
				dp[ns][0]=dp[s][0]+1;
				dp[ns][1]=dp[s][1];
			}
		}
	}
	int cnt=-1; ai2 pos{};
	for(int i=1;i<=n;++i){
		int s=full^a[i];
		if(!dp[s][1]) continue;
		const int c=dp[s][0];
		ai2 p={i,dp[s][1]};
		if(p[0]>p[1]) swap(p[0],p[1]);
		if(c>cnt || (c==cnt && p<pos)){
			cnt=c;
			pos=p;
		}
	}
	if(!pos[0]) cout<<"No";
	else{
		cout<<pos[0]<<' '<<pos[1];
	}
	return 0;
}
