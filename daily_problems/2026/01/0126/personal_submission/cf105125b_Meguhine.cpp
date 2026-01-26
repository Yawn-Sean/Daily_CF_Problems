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

#define NO {cout<<"NO\n";return;}
void solve(){
	int n; cin>>n;
	vector<int>a; a.reserve(n);
	vector<pair<int,int>>b; b.reserve(n);
	const int sum=[&]()->int {  // guaranteed <=5e5
		int res=0;
		for(int i=1,x;i<=n;++i){
			cin>>x;
			if(x==1) a.emplace_back(i);
			else if(x) b.emplace_back(i,x);
			res+=x;
		}
		return res;
	}();
	stringstream ans;
	auto fuckb=[&]()->bool {
		if(b.empty()) return 0;
		ans<<b.back().first<<' ';
		if(--b.back().second==1){
			a.emplace_back(b.back().first);
			b.pop_back();
		}
		return 1;
	};
	for(int i=1;i<=sum;++i){
		if(i&1){
			if(a.size()){
				ans<<a.back()<<' ';
				a.pop_back();
			}
			else{
				if(!fuckb()) NO;
			}
		}
		else{
			if(!fuckb()) NO;
		}
	}
	cout<<"YES\n"<<ans.str()<<'\n';
	dbg(a,b);
	assert(a.empty() && b.empty());
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
