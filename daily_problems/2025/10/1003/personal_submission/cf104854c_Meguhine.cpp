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

namespace FMF{ //find-max-factor
	using big=__int128_t;
	LL gcd(LL a,LL b){
		return b?gcd(b,a%b):a;
	}
	LL ksm(LL a,LL b,LL p){
		a%=p; LL res=1;
		while(b){
			if(b&1) res=(big)res*a%p;
			a=(big)a*a%p;
			b>>=1;
		}
		return res;
	}
	bool Miller_Rabin(LL p){ //判断素数
		if(p<2) return 0;
		if(p==2 || p==3 || p==5 || p==7 || p==43) return 1;
		LL d=p-1,r=0;
		while(!(d&1)) ++r,d>>=1; //将d处理为奇数
		for(LL k=0;k<10;k++) {
			LL a=rng()%(p-2)+2;
			LL x=ksm(a,d,p);
			if(x==1 || x==p-1) continue;
			for(int i=0;i<r-1;i++){
				x=(big)x*x%p;
				if(x==p-1) break;
			}
			if(x!=p-1) return 0;
		}
		return 1;
	}
	LL Pollard_Rho(LL x){
		LL s=0,t=0,c=rng()%(x-1)+1;
		int step=0,goal=1;
		LL val=1;
		for(goal=1;;goal<<=1,s=t,val=1){ //倍增优化
			for(step=1;step<=goal;step++){
				t=((big)t*t+c)%x;
				val=(big)val*abs(t-s)%x;
				if((step%127)==0){
					LL d=gcd(val,x);
					if(d>1) return d;
				}
			}
			LL d=gcd(val,x);
			if(d>1) return d;
		}
	}
	LL max_factor;
	void fac(LL x){
		if(x<=max_factor || x<2) return;
		if(Miller_Rabin(x)){ //如果x为质数
			max_factor=max(max_factor,x); //更新答案
			return;
		}
		LL p=x;
		while(p>=x) p=Pollard_Rho(x);  //使用该算法
		while((x%p)==0) x/=p;
		fac(x),fac(p); //继续向下分解x和p
	}
}

#define N 1000010
bool notP[N]; int mn_p[N];
vector<int>prime;
void init_prime(const int& n=N){//init [1,n-1]
	mn_p[1]=notP[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			notP[i*p]=1,mn_p[i*p]=p;
			if(i%p==0){
				break;
			}
		}
	}
}

/*
bp;
(bp+1)%(b+1)==b
(bp+2)%(b+2)==b
bp=k(b+1)(b+2)+b
b(p-1)=k(b+1)(b+2)
b+1 is factor of p-1
*/
using big=__int128_t;
struct Node{
	LL d; int c;
};
void solve(){
	LL p; cin>>p; --p;
	LL n=p;
	vector<Node>dv;
	while(n>=N){ //N是用筛法筛的质数的范围
		FMF::max_factor=0;
		FMF::fac(n);
		LL d=FMF::max_factor;
		int c=0;
		while(n%d==0) n/=d,++c;
		dv.emplace_back(d,c);
	}
	while(mn_p[n]!=1){
		LL d=mn_p[n];
		int c=0;
		while(n%d==0) n/=d,++c;
		dv.emplace_back(d,c);
	}
#ifdef LOCAL
	for(auto& [d,c]:dv){
		debug("\td=%lld c=%d\n",d,c);
	}
#endif
	vector<LL>ans;
	auto dfs=[&](auto&& self,int u,LL x){
		if(u==dv.size()){
			if(x==1) return;
			big i=(big)(p)*(x-1);
			big j=(big)(x)*(x+1);
			debug("x=%lld\n",x);
			if(i%j==0) ans.push_back(x-1);
			return;
		}
		for(int i=0;i<=dv[u].c;++i){
			self(self,u+1,x);
			x*=dv[u].d;
		}
	};
	dfs(dfs,0,1);
	cout<<ans.size()<<'\n';
	sort(all(ans));
	for(auto& x:ans) cout<<x<<' ';
	cout<<'\n';
}
int main(){
	init_prime();
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
