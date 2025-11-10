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

/*
1-based-index
if a[x]>a[x+1]
then must " x | x+1 "
so x%k==0
ans := d[gcd(all x)]
maintain gcd, use segtree
*/

#define N 200005
bitset<N>a;

#define ls (id<<1)
#define rs (id<<1|1)
struct Node{
	int l,r,g;
	friend Node operator +(const Node& A,const Node& B){
		Node ret;
		ret.l=A.l,ret.r=B.r;
		ret.g=__gcd(A.g,B.g);
		return ret;
	}
}q[N*4];
void build(int l,int r,int id=1){
	if(l==r){
		q[id].l=l,q[id].r=r;
		q[id].g=a[l]?l:0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	q[id]=q[ls]+q[rs];
}
void modify(int p,bool x,int id=1){
	if(q[id].l==q[id].r){
		q[id].g=x?q[id].l:0;
		return;
	}
	int mid=(q[id].l+q[id].r)>>1;
	if(p<=mid) modify(p,x,ls);
	else modify(p,x,rs);
	q[id]=q[ls]+q[rs];
}
int query(){return q[1].g;}
int get(int pos,int id=1){
	if(q[id].l==q[id].r) return q[id].g;
	int mid=(q[id].l+q[id].r)>>1;
	if(pos<=mid) return get(pos,ls);
	return get(pos,rs);
}
#undef ls
#undef rs

/*
f(n)=\sum_{d|n} g(d)
- g(n)=\sum_{d|n} mu(d)*f(n/d)
f(n)=\sum_{n|d} g(d)
- g(n)=\sum_{n|d} mu(d/n)f(d)
*/
bitset<N>notP;
int mu[N],mn_p[N];
int d[N],num[N];
vector<int>prime;
void init_prime(const int& n=N){ // init [1,n-1]
	mu[1]=mn_p[1]=notP[1]=1;
	d[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
			mu[i]=-1;
			d[i]=2,num[i]=1;
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			int j=i*p;
			notP[j]=1,mn_p[j]=p;
			if(i%p==0){
				mu[j]=0;
				num[j]=num[i]+1;
				d[j]=d[i]/num[j]*(num[j]+1);
				break;
			}
			mu[j]=-mu[i];
			num[j]=1;
			d[j]=d[i]*2;
		}
	}
}

void solve(){
	int n,Q;
	cin>>n>>Q;
	if(n==1){
		int sb; cin>>sb; cout<<"1\n";
		while(Q--){
			cin>>sb>>sb;
			cout<<"1\n";
		}
		return;
	}
	vector<int>o(n+1);
	for(int i=1;i<=n;++i) cin>>o[i];
	for(int i=1;i<n;++i){
		a[i]=(o[i]>o[i+1]);
	}
	build(1,n-1);
	auto fuck=[&]()->void{
		int x=query();
		if(!x) cout<<n<<'\n';
		else cout<<d[x]<<'\n';
	};
	fuck();
	for(int p,v;Q--;){
		cin>>p>>v;
		o[p]=v;
		if(p!=1) modify(p-1,o[p-1]>o[p]);
		if(p!=n) modify(p,o[p]>o[p+1]);
		fuck();
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init_prime();
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
