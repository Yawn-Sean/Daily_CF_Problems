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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<string>s(n);
	for(auto& t:s) cin>>t;
	vector<int>col(n);
	int ans=0;
	for(int j=0;j<n;++j){
		for(int i=0;i<n;++i){
			if(s[i][j]=='1'){
				++col[j];
				ans=1;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int cnt=0,mx=0;
			for(int k=0;k<n;++k){
				if(s[i][k]=='1' && s[j][k]=='1'){
					++cnt;
					updmx(mx,col[k]);
				}
			}
			updmx(ans,min(cnt,mx));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
