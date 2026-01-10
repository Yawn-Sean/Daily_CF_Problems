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

using Z=MI<998244353>;
#define raw(x) Z::raw(x)

constexpr int N=1e6+5;
namespace Fac{ // factorial
	Z fc[N],fc_inv[N];
	void init(){
		fc[0]=fc_inv[0]=raw(1);
		for(int i=1;i<N;i++){
			fc[i]=fc[i-1]*raw(i);
		}
		fc_inv[N-1]=fc[N-1].inv();
		for(int i=N-2;i>0;i--){
			fc_inv[i]=fc_inv[i+1]*raw(i+1);
		}
	}
	Z P(const int x,const int y){
		return fc[x]*fc_inv[x-y];
	}
	Z C(const int x,const int y){
		if(x==y) return raw(1);
		if(x<0 || y<0 || x-y<0) return raw(0);
		return fc[x]*fc_inv[y]*fc_inv[x-y];
	}
}

bool a[N];

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	Fac::init();
	int n; cin>>n;
	const bool even=!(n&1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1];
		exit(0);
	}
	Z ans=raw(1); int mul=1;
	for(int i=n;i>0;--i){
		if(a[i]){
			if(!mul){
				cout<<"0\n";
				exit(0);
			}
			ans*=raw(mul-even);
			--mul;
		}
		else{
			ans*=raw(mul);
			++mul;
		}
	}
	if(mul!=0 && mul!=1) ans=raw(0);
	cout<<ans.val();
	return 0;
}

/*
just trivial multiplication
take the following as an example

```text
7
1 1 0 1 0 1 0
```

calc ans from the last element

element, ans, next_mul
0, 1, 2
1, 2, 1
0, 2, 2
1, 4, 1
0, 4, 2
1, 8, 1
1, 8, 0
*/
