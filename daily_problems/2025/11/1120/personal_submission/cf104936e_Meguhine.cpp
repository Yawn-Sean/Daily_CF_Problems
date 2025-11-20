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

template<class S>
struct MinXor{
	static_assert(std::is_integral_v<S>);
	multiset<S>a,b;
	void insert(S x){
		auto it=a.insert(x);
		auto nxt=next(it);
		if(it!=a.begin()){
			auto pre=prev(it);
			if(nxt!=a.end()) b.extract(*nxt^*pre);
			b.insert(*it^*pre);
		}
		if(nxt!=a.end()) b.insert(*nxt^*it);
	}
	void extract(S x){
		auto it=a.find(x);
		if(it==a.end()) return;
		auto nxt=next(it);
		if(it!=a.begin()){
			auto pre=prev(it);
			if(nxt!=a.end()) b.insert(*nxt^*pre);
			b.extract(*it^*pre);
		}
		if(nxt!=a.end()) b.extract(*nxt^*it);
		a.erase(it);
	}
	S min() const{
		if(b.empty()) return S(-1);
		return *b.begin();
	}
};

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,X; cin>>n>>X;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	vector<int>l(n,-1);
	{
		MinXor<int>s;
		s.insert(a[0]);
		s.insert(a[1]);
		for(int i=0,j=1;i<n;++i){
			while(j+1<n && (j-i+1<2 || s.min()>X)){
				s.insert(a[++j]);
			}
			if(s.min()==X) l[i]=j;
			dbg(i,j,s.min());
			s.extract(a[i]);
		}
	}
	vector<int>r(n);
	{
		MinXor<int>s;
		s.insert(a[0]);
		s.insert(a[1]);
		for(int i=0,j=1;i<n;++i){
			while(j+1<n && (j-i+1<2 || s.min()>=X)){
				s.insert(a[++j]);
				if(j-i+1>2 && s.min()<X){
					dbg("\t",i,j,s.min());
					s.extract(a[j--]);
					break;
				}
			}
			if(s.min()==X) r[i]=j;
			dbg(i,j,s.min());
			s.extract(a[i]);
		}
	}
	LL ans=0;
	for(int i=0;i<n;++i){
		if(l[i]!=-1) ans+=r[i]-l[i]+1;
		dbg(i,l[i],r[i]);
	}
	cout<<ans;
	return 0;
}
