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

#define sz(x) (int)((x).size())
template<typename T>
struct Med{
	multiset<T>a,b; // a:<=med, b:>=med
	LL sa,sb;
	//a.size()==b.size()+1 || a.size()==b.size()
	Med(){init();}
	void init(){
		clr(a),clr(b);
		sa=sb=0;
	}
	void rua(){
		if(sz(a)<sz(b)){
			auto it=b.begin();
			sa+=*it,sb-=*it;
			a.insert(*it);
			b.erase(it);
		}
		else if(sz(a)>sz(b)+1){
			auto it=--a.end();
			sa-=*it,sb+=*it;
			b.insert(*it);
			a.erase(it);
		}
	}
	void add(T x){
		if(b.empty() || x<=*b.begin()){
			a.insert(x);
			sa+=x;
		}
		else{
			b.insert(x);
			sb+=x;
		}
		rua();
	}
	void del(T x){
		auto it=a.find(x);
		if(it!=a.end()){
			a.erase(it);
			sa-=x;
		}
		else{
			b.extract(x);
			sb-=x;
		}
		rua();
	}
	T med_single() const{
		return *--a.end();
	}
	array<T,2> med_range() const{
		T l=med_single();
		if(sz(a)==sz(b)+1) return {l,l}; 
		return {l,*b.begin()};
	}
	LL cost() const{ // adjust all number to median's cost
		T mid=med_single();
		return (1ll*mid*a.size()-sa) + (sb-1ll*mid*b.size());
	}
};
#undef sz

void solve(){
	int n; LL m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0,x;i<n;++i){
		cin>>x;
		a[i]=x-i;
	}
	Med<int>med;
	med.add(a[0]);
	int ans=1,r=0;
	for(int i=0;i<n;++i){
		while(r+1<n){
			med.add(a[++r]);
			if(med.cost()>m){
				med.del(a[r--]);
				break;
			}
		}
		updmx(ans,r-i+1);
		dbg(i,r,med.med_single(),med.cost());
		med.del(a[i]);
	}
	cout<<ans<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
