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

/*
since n is odd, ans must exist
we only check odd index (1,3,...,n)
use binary search
*/

#ifdef LOCAL
constexpr int N=2005;
int a[N],b[N];
void _get(int& x,const vector<int>& o){
	// cin>>x; return;
	if(o.empty()){
		x=rand(1,1e9);
	}
	else{
		x=o[rng()%o.size()];
	}
}
#endif

bool ask(int x){
	int p,q;
	cout<<"1 "<<(x-1)<<endl;
#ifndef LOCAL
	cin>>p;
#else
	p=a[x-1];
#endif
	cout<<"2 "<<x<<endl;
#ifndef LOCAL
	cin>>q;
#else
	q=b[x];
#endif
	return p==q;
}
void solve(){
	int n; cin>>n;
#ifdef LOCAL
	for(int i=1;i<=n;++i){
		_get(a[i],{});
	}
	_get(b[1],{a[2]});
	assert(b[1]==a[2]);
	for(int i=2;i<n;++i){
		_get(b[i],{a[i-1],a[i+1]});
		// assert(b[i]==a[i-1] || b[i]==a[i+1]);
	}
	_get(b[n],{a[n-1]});
	assert(b[n]==a[n-1]);
	dbg(a);
	dbg(b);
#endif
	int l=1,r=n,mid;
	while(l+2<r){
		mid=(l+r)>>1;
		if(!(mid&1)) ++mid;
		dbg(l,r,mid);
		if(ask(mid)) r=mid;
		else l=mid;
	}
	cout<<"3 "<<l<<' '<<r<<endl;
#ifdef LOCAL
	assert(b[l]==b[r]);
#endif
}

int main(){
#ifdef LOCAL
	dbg(114514);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
