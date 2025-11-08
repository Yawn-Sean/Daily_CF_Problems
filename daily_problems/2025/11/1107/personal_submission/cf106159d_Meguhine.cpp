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

#define vi vector<int>
void kmp(const auto& s,vi& pi) {
	const int n=(int)s.size();
	pi.assign(n,0);
	for(int i=1;i<n;++i){
		int j=pi[i-1];
		while(j>0 && s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) ++j;
		pi[i]=j;
	}
}
// s is text, t is pattern to be found
void kmp(const auto& s,const auto& t,vi& v,const auto& sep){
#define TP(x) std::decay_t<decltype(x)>
	static_assert(std::is_same_v<TP(s),TP(t)>);
	static_assert(std::is_same_v<TP(s[0]),TP(sep)>);
#undef TP
	const int n=(int)s.size();
	const int m=(int)t.size();
	auto cur=t; cur.push_back(sep);
	cur.insert(cur.end(),all(s));
	vi lps; kmp(cur,lps); clr(v);
	for(int i=m+1;i<=n+m;++i){
		if(lps[i]==m) v.emplace_back(i-2*m);
	}
}
#undef vi

constexpr int M=10000;
inline void adjust(int& x){
	if(x<0) x+=M;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>a(n),b(m);
	for(auto& x:a) cin>>x;
	for(auto& x:b) cin>>x;
	vector<int>da(n-1),db(m-1);
	for(int i=1;i<n;++i){
		adjust(da[i-1]=a[i]-a[i-1]);
	}
	for(int i=1;i<m;++i){
		adjust(db[i-1]=b[i]-b[i-1]);
	}
	vector<int>v;
	kmp(da,db,v,-1);
	array<int,M>cnt{};
	for(auto& x:v){
		dbg(x,a[x]);
		++cnt[a[x]];
	}
	int ans=0,shift=0;
	for(int i=0,x;i<M;++i){
		adjust(x=b[0]-i);
		if(cnt[i]>ans || (cnt[i]==ans && x<shift)){
			ans=cnt[i];
			shift=x;
		}
	}
	cout<<shift<<' '<<ans;
	return 0;
}
