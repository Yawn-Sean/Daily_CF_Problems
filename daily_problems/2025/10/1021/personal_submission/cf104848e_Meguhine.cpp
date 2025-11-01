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

int calc(LL x){
	vector<int>a;
	while(x){
		a.emplace_back(x%10);
		x/=10;
	}
	vector<int>p(a);
	iota(all(p),0);
	LL g=0;
	do{
		LL r=0;
		for(auto& i:p){
			r=r*10+a[i];
		}
		g=gcd(g,r);
		if(g==1) break;
	}while(next_permutation(all(p)));
	return (int)g;
}

/*
constexpr int N=100;
LL ans[N];
bool flag[N];
void init(){
	set<int>pt;
	auto add=[&](int x)->void{
		pt.insert(x);
		for(int i=2;i*i<=x;++i){
			if(x%i) continue;
			pt.insert(i);
			pt.insert(x/i);
		}
	};
	for(int i=1;i<=9;++i){
		add(9*i);
	}
	vector<int>a;
	for(auto& x:pt){
		if(x>10) a.emplace_back(x);
	}
	for(auto& x:a){
		dbg(x);
		flag[x]=1;
	}
	constexpr int M=1e6;
	for(int i=11;i<M;++i){
		int g=calc(i);
		if(g<N && flag[g] && !ans[g]) ans[g]=i;
	}
	for(auto& x:a){
		dbg(x,ans[x]);
	}
}
*/
/*
x = 12 (int32_t&), ans[x] = 48 (long long int&)
x = 15 (int32_t&), ans[x] = 5055 (long long int&)
x = 18 (int32_t&), ans[x] = 288 (long long int&)
x = 21 (int32_t&), ans[x] = 7077 (long long int&)
x = 24 (int32_t&), ans[x] = 8088 (long long int&)
x = 27 (int32_t&), ans[x] = 3699 (long long int&)
x = 36 (int32_t&), ans[x] = 48888 (long long int&)
x = 45 (int32_t&), ans[x] = 0 (long long int&)
x = 54 (int32_t&), ans[x] = 0 (long long int&)
x = 63 (int32_t&), ans[x] = 111888 (long long int&)
x = 72 (int32_t&), ans[x] = 0 (long long int&)
x = 81 (int32_t&), ans[x] = 0 (long long int&)
*/

LL ans[100];
void init_cheat(){ // skip the brute force search
	memset(ans,-1,sizeof(ans));
	ans[12] = 48;
	ans[15] = 5055;
	ans[18] = 288;
	ans[21] = 7077;
	ans[24] = 8088;
	ans[27] = 3699;
	ans[36] = 48888;
	ans[45] = 5055555555ll; // sp
	ans[54] = 222888888; // sp
	ans[63] = 111888;
	ans[72] = 8088888888ll; // sp
	ans[81] = 9099999999ll; // sp
}

bool fuck(LL x){
	int y=x%10;
	while(x){
		if((x%10)!=y) return 0;
		x/=10;
	}
	return 1;
}
void solve(){
	LL n; cin>>n;
	if(fuck(n)){
		cout<<n<<'\n';
		return;
	}
	if(n>=100){
		cout<<"-1\n";
		return;
	}
	cout<<ans[n]<<'\n';
}
int main(){
//	while(1){
//		LL x;
//		cin>>x;
//		cout<<calc(x)<<'\n';
//	}
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init_cheat();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
