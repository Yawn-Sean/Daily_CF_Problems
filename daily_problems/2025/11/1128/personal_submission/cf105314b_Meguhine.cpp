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
	int n; LL m; cin>>n>>m;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	sort(all(a));
	LL res,cnt;
	vector<LL>s(n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i-1];
	auto get=[&](int l,int r)->LL{
		return s[r+1]-s[l];
	};
	auto check=[&](int x)->LL{
		res=cnt=0;
		for(int i=0,j=0;i<n;++i){
			while(j<n && a[j]-a[i]<x) ++j;
			if(j==n) break;
			const int c=n-j;
			cnt+=c*2;
			res+=(get(j,n-1)-1ll*a[i]*c)*2;
		}
		return cnt;
	};
	int l=0,r=a[n-1]-a[0],mid,opt=-1;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)>=m){
			opt=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	assert(opt!=-1);
	check(opt);
	res-=(cnt-m)*opt;
	cout<<res<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
