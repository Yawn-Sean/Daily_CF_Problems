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

void solve(){
	int n; string s;
	cin>>n>>s;
	int ans=0;
	int l=0,r=n-1;
	while(l<n && s[l]=='?') ++l;
	while(~r && s[r]=='?') --r;
	dbg(l,r);
	int last=l;
	for(int i=l;i<=r;++i){
		if(s[i]!='?'){
			++ans;
			int len=i-last-1;
			dbg(len);
			if(len>0){
				if(len==1){
					if(s[last]!=s[i]) ++ans;
				}
				else ++ans;
			}
			last=i;
		}
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
