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

#define D constexpr MI
#define C const
#define O operator
template<unsigned int mod>struct MI{
	D():v(0){}
	template<typename T>
	D(T x):v(x%mod){if(v<0) v+=mod;}
	template<typename T>
	static D raw(T x){MI z; z.v=x; return z;}
	D pow(LL n) C {
		MI x=*this, r=1;
		while(n){if(n&1) r*=x; x*=x; n>>=1;}
		return r;
	}
	D inv() C {return pow(mod-2);}
	D& O +=(C MI& x){
		if((v+=x.v)>=mod) v-=mod;
		return *this;
	}
	D& O -=(C MI& x){
		if((v-=x.v)<0) v+=mod;
		return *this;
	}
	D& O *=(C MI& x){
		LL z=v; z*=x.v; v=z%mod;
		return *this;
	}
	D& O /=(C MI& x){
		return *this=*this*x.inv();
	}
	int val() C{return v;}
	static constexpr unsigned int umod(){return mod;}
#define OP(s,t) friend D O s(C MI& x,C MI& y){return MI(x) t y;}
	OP(+,+=) OP(-,-=) OP(*,*=) OP(/,/=)
#undef OP
private:
	int v;
};
#undef D
#undef C
#undef O

using Z=MI<(int)(1e9+7)>;
#define raw(x) Z::raw(x)

void solve(){
	int n,Q;
	cin>>n>>Q;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	const int m=[&]()->int { // discrete a
		vector<int>b={a.begin()+1,a.end()};
		sort(all(b));
		b.erase(unique(all(b)),b.end());
		for(int i=1;i<=n;++i) a[i]=lower_bound(all(b),a[i])-b.begin()+1;
		return b.size();
	}();
	vector<vector<int>>pos(m+1);
	vector<int>id(n+1); // id[i] is the position of i in pos[a[i]]
	for(int i=1;i<=n;++i){
		pos[a[i]].push_back(i);
		id[i]=(int)pos[a[i]].size();
	}
	vector<int>R(n+1); // for a given k, R[k] is the end point
	{ // calculate R
		int k_nw=0,k_mx=0,mx=0;
		for(int i=1;i<=n;++i){
			if(updmx(mx,a[i])) k_nw=0;
			else updmx(k_mx,++k_nw);
			if(!R[k_mx]) R[k_mx]=i;
		}
		for(int i=1;i<=n;++i){
			if(!R[i]) R[i]=n;
		}
		R[0]=0;
	}
	vector<int>mx(n+1);
	for(int i=1;i<=n;++i) mx[i]=max(mx[i-1],a[i]);
	#ifdef LOCAL
	for(int i=1;i<=n;++i){
		dbg(i,R[i]);
	}
	#endif
	auto calc=[&](int i,int k)->int {
		const int r=R[k];
		if(i>r || a[i]!=mx[r]) return 0;
		const int cnt=upper_bound(all(pos[a[i]]),r)-pos[a[i]].begin();
		return raw(2).pow(cnt-id[i]+(id[i]!=1)).inv().val();
	};
	for(int op,i,k;Q--;){
		cin>>op>>i;
		if(op==1){
			cin>>k;
			cout<<calc(i,k)<<"\n";
		}
		else{
			k=lower_bound(all(R),i)-R.begin();
			dbg(i,k,R[k]);
			cout<<k<<' '<<calc(i,k)<<"\n";
		}
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	solve();
	return 0;
}
