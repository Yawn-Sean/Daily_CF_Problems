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

constexpr int N=2e5+5;
namespace ST_C{ // Sparse Table Constant
	int Logn[N];
	void init(){
		Logn[1]=0,Logn[2]=1;
		for (int i=3;i<N;i++) {
			Logn[i]=Logn[i/2]+1;
		}
	}
}
template<class T,auto op>
class ST{
	using VT=vector<T>;
	using VVT=vector<VT>;
	VVT a;
public:
	ST(){}
	ST(const vector<T> &v,int n){
		init(v,n); // v is 1-index
	}
	void init(const vector<T> &v,int n){
		int mx_l=ST_C::Logn[n]+1; // max log
		a.assign(n+1,VT(mx_l,0));
		for(int i=1;i<=n;i++){
			a[i][0]=v[i];
		}
		for(int j=1;j<mx_l;j++){
			int p=(1<<(j-1));
			for(int i=1;i+p<=n;i++){
				a[i][j]=op(a[i][j-1],a[i+p][j-1]);
			}
		}
	}
	T query(int l,int r){
		int lt=r-l+1;
		int p=ST_C::Logn[lt];
		return op(a[l][p],a[r-(1<<p)+1][p]);
	}
};
int op(int x,int y){
	return x&y;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	ST_C::init(); // init
	int n,k,q;
	cin>>n>>k>>q;
	vector<int>a(n+1);
	for(int i=1,x;i<=n;++i){
		cin>>x;
		if((~x)&k) x=-1;
		a[i]=x;
	}
	ST<int,op>st(a,n); // usage
	for(int l,r;q--;){
		cin>>l>>r;
		cout<<(st.query(l,r)==k?"YES":"NO")<<'\n';
	}
	return 0;
}
