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

void zfunc(const auto& s,vector<int>& z){
	int n=(int)s.size();
	z.assign(n,0);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r && z[i-l]<r-i+1) z[i]=z[i-l];
		else{
			z[i]=max(0,r-i+1);
			while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
				++z[i];
			}
		}
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	string t=s+s;
	for(int i=n;i<n*2;++i){
		t[i]^=('0'^'1');
	}
	vector<int>z,ans(n);
	zfunc(t,z);
	for(int i=n;i<n*2;++i){
		if(z[i]) updmx(ans[i+z[i]-1-n],z[i]);
	}
	for(int i=n-2;i>=0;--i){
		updmx(ans[i],ans[i+1]-1);
	}
	for(auto x:ans) cout<<x<<' ';
	cout<<'\n';
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
