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

int ask(int i,int j){
	cout<<"? "<<i<<' '<<j<<endl;
	int x; cin>>x;
	return x;
}

int main(){
	int n; cin>>n;
	int one=1;
	for(int i=2;i<=n;++i){
		if(i==one) continue;
		one=ask(one,i);
	}
	list<int>r;
	vector<int>ans;
	for(int i=1;i<=n;++i){
		if(i!=one) r.push_back(i);
	}
	while(r.size()){
		auto it=r.begin();
		int p=*it;
		for(it=r.erase(it);it!=r.end();){
			const int i=*it;
			const int x=ask(p,i);
			if(x==one){
				++it;
				continue;
			}
			p=x;
			it=r.erase(it);
		}
		ans.emplace_back(p);
	}
	cout<<"! "<<ans.size();
	for(auto x:ans) cout<<' '<<x;
	return 0;
}
