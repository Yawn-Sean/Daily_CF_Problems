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

using B=bitset<10>;
#define OUT {cout<<ans<<'\n';return;}

void solve(){
	string s; cin>>s;
	const int n=(int)(s.size());
	vector<int>last;
	array<vector<int>,10>pos{};
	for(int i=0;i<n;++i){
		pos[s[i]-'0'].emplace_back(i);
	}
	auto next_pos=[&](int p,char c)->int{
		auto& a=pos[c-'0'];
		auto it=lower_bound(all(a),p);
		if(it==a.end()) return -1;
		return (*it)+1;
	};
	string ans="";
	for(int i=n-1;~i;--i){
		B b; b.set();
		while(i>=0 && b.any()){
			b.reset(s[i--]-'0');
		}
		if(b.none()){
			last.emplace_back(++i);
		}
		else{
			if(last.empty() && b[0]) ans="0";
			else{
				for(int x=1;x<10;++x){
					if(b[x]){
						ans=(char)('0'+x);
						break;
					}
				}
				if(ans.empty()) ans="10";
			}
			break;
		}
	}
	if(ans.empty()) ans="1";
	dbg("prefix",ans);
	int nw=0;
	for(auto c:ans){
		nw=next_pos(nw,c);
		if(nw==-1){
			OUT;
		}
	}
	dbg("begin fucking");
	while(last.size()){
		last.pop_back();
		bool f=0;
		for(char c='0';c<='9';++c){
			int nnw=next_pos(nw,c);
			if(nnw==-1){
				ans+=c;
				OUT;
			}
			if(last.size() && nnw>last.back()){
				ans+=c;
				nw=nnw;
				f=1;
				break;
			}
		}
		assert(f);
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
