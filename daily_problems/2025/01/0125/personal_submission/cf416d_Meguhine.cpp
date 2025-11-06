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
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	auto check=[&](int l,int r)->bool{
		int p0=-1,p1=-1;
		for(int i=l;i<=r;++i){
			if(a[i]!=-1){
				if(p0==-1) p0=i;
				else{
					p1=i;
					break;
				}
			}
		}
		if(p1==-1) return 1;
		int d=(a[p1]-a[p0])/(p1-p0);
		if(d*(p1-p0)!=(a[p1]-a[p0])) return 0;
		LL x=-1ll*d*(p0-l)+a[p0];
		for(int i=l;i<=r;++i){
			if(x<=0 || (a[i]!=-1 && a[i]!=x)) return 0;
			x+=d;
		}
		return 1;
	};
	int ans=0,last=-1;
	while(last<n-1){
		int st=last+1;
		int l=st+2,r=n-1,mid,opt=st+1;
		while(l<=r){
			mid=l+r>>1;
			if(check(st,mid)){
				l=mid+1;
				opt=mid;
			}
			else r=mid-1;
		}
		dbg(st,opt);
		++ans;
		last=opt;
	}
	cout<<ans;
	return 0;
}
