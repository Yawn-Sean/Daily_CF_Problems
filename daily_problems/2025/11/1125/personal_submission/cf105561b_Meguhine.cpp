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

constexpr int N=1e6+5;
bitset<N>notP; int mn_p[N];
vector<int>prime;
void init_prime(const int& n=N){ // init [1,n-1]
	mn_p[1]=notP[1]=1;
	for(int i=2;i<n;i++){
		if(!notP[i]){
			prime.push_back(mn_p[i]=i);
		}
		for(const int& p:prime){
			if(i>(n-1)/p) break;
			notP[i*p]=1,mn_p[i*p]=p;
			if(i%p==0){
				break;
			}
		}
	}
}

int work(int x){
	int r=1;
	while(1){
		int p=mn_p[x];
		if(p==1) break;
		r*=p;
		while(x%p==0) x/=p;
	}
	return r;
}

bitset<N>ok;
void init(int x){
	vector<int>d;
	while(1){
		int p=mn_p[x];
		if(p==1) break;
		d.emplace_back(p);
		while(x%p==0) x/=p;
	}
	auto dfs=[&](auto&& self,int u,int r)->void{
		if(u==d.size()){
			ok[r]=1;
			return;
		}
		self(self,u+1,r);
		self(self,u+1,r*d[u]);
	};
	dfs(dfs,0,1);
}

namespace BF{
	constexpr int inf=1e9;
	int ksm(int a,int b){ // a,b >= 2
		if(a>=inf) return inf;
		int r=1; bool f=0;
		while(b){
			if(b&1){
				if(f || !(r<=inf/a)){
					return inf;
				}
				r*=a;
			}
			if(a<=inf/a) a*=a;
			else f=1;
			b>>=1;
		}
		return r;
	}
	struct Node{
		int x,nw,need;
		friend Node operator +(const Node& u,const Node& v){
			Node r;
			r.x=ksm(u.x,v.x);
			constexpr int m=20;
			if(!u.nw) r.nw=0;
			else if(u.nw>=m || v.x>=m) r.nw=m;
			else r.nw=u.nw*v.x;
			r.need=u.need;
			return r;
		}
		Node operator +=(const Node& v){
			return *this=(*this+v);
		}
	};
	Node trans(const int o,const int x){
		LL r=o%x; int nd=1;
		while(r && nd<=20){
			++nd;
			r=r*o%x;
		}
		if(r) return Node{o,0,1};
		else return Node{o,1,nd};
	}
	bool check_3(auto&& A,const int X){
		array<Node,3>base{
			trans(A[0],X),trans(A[1],X),trans(A[2],X)
		};
		ai3 p{0,1,2};
		do{
			array<Node,3>a;
			for(int i=0;i<3;++i) a[i]=base[p[i]];
			a[0]+=a[1];
			a[1]+=a[2];
			a[0]+=a[1];
			if(a[0].nw>=a[0].need) return 1;
		}while(next_permutation(all(p)));
		return 0;
	}
	bool check_2(auto&& A,const int X,const int c1){
		if(c1>=5) return 1;
		array<Node,2>a{trans(A[0],X),trans(A[1],X)};
		dbg(a[0].x,a[0].nw,a[0].need);
		dbg(a[1].x,a[1].nw,a[1].need);
		for(int s=0;s<(1<<c1);++s){
			Node x=a[0],y=a[1];
			for(int i=0;i<c1;++i){
				if(s>>i&1) x+=y;
				else y+=x;
			}
			Node z1=x+y;
			Node z2=y+x;
			if(z1.nw>=z1.need || z2.nw>=z2.need) return 1;
		}
		return 0;
	}
}

#define OK {cout<<"Yes\n";continue;}
#define FAIL {cout<<"No\n";continue;}

void solve(){
	ok.reset();
	int n,Q;
	cin>>n>>Q;
	int c1=0;
	vector<int>a;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		if(x==1) ++c1;
		else{
			init(x);
			a.emplace_back(x);
		}
	}
	for(int x,X;Q--;){
		cin>>X;
		if(X==1) OK;
		x=work(X);
		if(!ok[x]) FAIL;
		if(x==X) OK;
		if(a.size()>=4) OK;
		if(a.size()==3){
			if(c1>=1) OK;
			if(BF::check_3(a,X)) OK;
		}
		if(a.size()==2){
			if(BF::check_2(a,X,c1)) OK;
		}
		if(a.size()==1){
			if(a[0]%X==0) OK;
		}
		FAIL;
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	init_prime();
	solve();
//	int t; cin>>t; while(t--) solve();
	return 0;
}
