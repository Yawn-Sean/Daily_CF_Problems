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

template<typename T>//T is int or LL
class Fenwick{
private:
	int n;
	vector<T>c;
	inline int lowbit(const int& x){
		return x&(-x);
	}
public:
	Fenwick(){}
	Fenwick(int n_){
		init(n_);
	}
	void init(int n_){
		c.assign(n=n_,T(0));
	}
	void add(int i,T x){
		for(;i<n;i+=lowbit(i)) c[i]+=x;
	}
	T query(int i){
		T res=0;
		for(;i;i-=lowbit(i)) res+=c[i];
		return res;
	}
};

LL work(auto&& a,int n){
	Fenwick<int>fen(n+1);
	LL r=0;
	for(int i=n-1;i>=0;--i){
		r+=fen.query(a[i]);
		fen.add(a[i],1);
	}
	return r;
}
void solve(){
	int n; cin>>n;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	vector<int>b(n);
	// n/2: 1   n/2+1: n
	for(int i=0,odd=3,even=2;i<n;++i){
		if(a[i]==n/2) b[i]=1;
		else if(a[i]==n/2+1) b[i]=n;
		else if(a[i]<n/2){
			b[i]=odd;
			odd+=2;
		}
		else{
			b[i]=even;
			even+=2;
		}
	}
	LL x=work(b,n);
	// n/2: n   n/2+1: 1
	for(int i=0,odd=3,even=2;i<n;++i){
		if(a[i]==n/2) b[i]=n;
		else if(a[i]==n/2+1) b[i]=1;
		else if(a[i]>n/2){
			b[i]=odd;
			odd+=2;
		}
		else{
			b[i]=even;
			even+=2;
		}
	}
	LL y=work(b,n);
	cout<<(1ll*n*n/2-1)<<' '
		<<min(x,y)<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
