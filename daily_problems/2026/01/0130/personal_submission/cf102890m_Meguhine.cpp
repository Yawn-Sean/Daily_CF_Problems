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

ai10 operator +(ai10 x,const ai10& y){
	for(int i=1;i<=9;++i) x[i]+=y[i];
	return x;
};
ai10 operator -(ai10 x,const ai10& y){
	for(int i=1;i<=9;++i) x[i]-=y[i];
	return x;
}
bool operator <=(const ai10& x,const ai10& y){
	for(int i=1;i<=9;++i) if(x[i]>y[i]) return 0;
	return 1;
}
bool hasv(const ai10& x){
	for(int i=1;i<=9;++i) if(x[i]) return 1;
	return 0;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	string s; cin>>s;
	const int n=int(s.size());
	ai10 del{};
	for(int i=1;i<=9;++i) cin>>del[i];
	vector to(n,ai10{});
	{
		for(int i=1;i<=9;++i) to[n-1][i]=-1;
		to[n-1][s[n-1]-'0']=n-1;
	}
	for(int i=n-2;~i;--i){
		for(int x=1;x<=9;++x) to[i][x]=to[i+1][x];
		to[i][s[i]-'0']=i;
	}
	vector sum(n+1,ai10{});
	for(int i=1;auto c:s){
		sum[i]=sum[i-1];
		++sum[i++][c-'0'];
	}
	auto get=[&](int l,int r){ // 0-index-based
		return sum[r+1]-sum[l];
	};
	vector<int>ans; ans.reserve(n);
	int i=0;
	while(1){
		dbg(i);
		bool f=0,ok=0;
		for(int x=9;x>=1;--x){
			const int j=to[i][x];
			if(j==-1) continue;
			const ai10 l=get(i,j-1);
			const ai10 r=get(j+1,n-1);
			#ifdef LOCAL
			auto __l=l,__r=r;
			dbg(x,i,j);
			dbg(__l);
			dbg(__r);
			dbg(del);
			dbg(l<=del,del<=(l+r));
			#endif
			if(l<=del && del<=(l+r)){
				dbg("choose",x,j);
				ans.emplace_back(j);
				i=j+1;
				del=del-l;
				if(del==r) f=1;
				else if(!hasv(del)){
					for(;i<n;++i) ans.emplace_back(i);
					f=1;
				}
				ok=1;
				break;
			}
		}
		assert(ok);
		if(f) break;
	}
	for(auto x:ans) cout<<s[x];
	return 0;
}
