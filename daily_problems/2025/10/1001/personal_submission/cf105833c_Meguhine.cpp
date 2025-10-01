#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
char DEBUG_BUFFER[1000];
#define debug(...) {sprintf(DEBUG_BUFFER,##__VA_ARGS__);\
cerr<<"\033[1;36m"<<DEBUG_BUFFER<<"\033[0;2m"<<"\033[0m";\
fflush(stderr);}
#define s S.c_str()
char TEST_GEN[1000],TEST_ANS[1000],TEST_OUT[1000],TEST_FC[1000];
void TEST(string S){
	sprintf(TEST_GEN,"%s_gen.exe > %s_input.txt",s,s);
	sprintf(TEST_ANS,"%s_sol.exe < %s_input.txt > %s_ans.txt",s,s,s);
	sprintf(TEST_OUT,"%s.exe < %s_input.txt > %s_out.txt",s,s,s);
	sprintf(TEST_FC,"fc %s_ans.txt %s_out.txt /n",s,s);
	while(1){
		debug("gen\n"); system(TEST_GEN);
		debug("ans\n"); system(TEST_ANS);
		debug("out\n"); system(TEST_OUT);
		if(system(TEST_FC)) break;
	}
}
#undef s
#else
#define debug(...) ;
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
int rand(int l,int r){return rng()%(r-l+1)+l;}

#define N 5005
int n,h[N],d[N],c[N];
int dp[N][N];

const int inf=0xC0C0C0C0;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	cin>>n;
	for(int i=1;i<=n;++i) cin>>h[i];
	for(int i=1;i<=n;++i) cin>>d[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	memset(dp,0xC0,sizeof(dp));
	dp[n][d[n]]=min(h[n],d[n])-c[n];
	dp[n][0]=0;
	for(int i=n-1;i>0;--i){
		for(int j=0;j<N;++j) if(dp[i+1][j]!=inf){
			updmx(dp[i][j],dp[i+1][j]+min(h[i],j));
			int x=min(j+d[i],N-1);
			updmx(dp[i][x],dp[i+1][j]+min(h[i],x)-c[i]);
		}
	}
	cout<<*max_element(dp[1],dp[1]+N);
	return 0;
}
