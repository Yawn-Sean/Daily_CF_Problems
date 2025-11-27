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
S(x)=x (r=0)
S(x)=1 (r=1)
S(x)=x+1 (r=2)
S(x)=0 (r=3)

for n, get max x.
sort below means sort these value

x==n, 1 op, sort all
x+1==n:
	x:   xxx0111 11
	x+1: xxx1000 00
	find: 0001111 11
		find ok, ok
		else -1
x+2==n:
	sort 1~x
	sort x-1~x+2
	sort 1~x
x+3==n:
	x-2: xxxx01
	x-1: xxxx10
	x:   xxxx11
	x+1: yyyy00
	x+2: yyyy01
	x+3: yyyy10
	sort 1~x
	sort x-1~x+2
	sort 1~x
	sort x-3,x,x+2,x+3
	sort 1~x
	sort x-1~x+2
	sort 1~x
*/

#define FAIL {cout<<"-1\n";return;}
void solve(){
	int n; cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=2){
		if(is_sorted(all(a))) cout<<"0\n";
		else cout<<"-1\n";
		return;
	}
	auto check=[&]()->void{
		assert(is_sorted(all(a)));
	};
	auto work=[&](int l,int r)->void{
		vector<int>o;
		for(int i=1;i<=n;++i){
			if(l<=a[i] && a[i]<=r){
				o.emplace_back(i);
			}
		}
		assert((int)o.size()==r-l+1);
		cout<<o.size();
		int tot=l;
		for(auto x:o){
			cout<<' '<<x;
			a[x]=tot++;
		}
		cout<<'\n';
	};
	auto work2=[&](auto&& ck)->void{
		vector<int>o;
		for(int i=1;i<=n;++i){
			if(find(all(ck),a[i])!=ck.end()){
				o.emplace_back(i);
			}
		}
		assert(o.size()==ck.size());
		cout<<o.size();
		int tot=0;
		for(auto x:o){
			cout<<' '<<x;
			a[x]=ck[tot++];
		}
		cout<<'\n';
	};
	const int x=(n-3)/4*4+3;
	if(x==n){
		cout<<"1\n";
		work(1,x);
		check();
		return;
	}
	if(x+1==n){
		if(a[n]==n){
			cout<<"1\n";
			work(1,x);
			check();
			return;
		}
		int need=x^(x+1);
		if(need>n) FAIL;
		cout<<"3\n";
		work(1,x);
		work2(vector<int>{need,x,x+1});
		work(1,x);
		check();
		return;
	}
	if(x+2==n){
		cout<<"3\n";
		work(1,x);
		work(x-1,x+2);
		work(1,x);
		check();
		return;
	}
	if(x+3==n){
		cout<<"7\n";
		work(1,x);
		work(x-1,x+2);
		work(1,x);
		{
			vector<int>o{};
			if(x>3) o={x-3};
			o.insert(o.end(),{x,x+2,x+3});
			work2(o);
		}
		work(1,x);
		work(x-1,x+2);
		work(1,x);
		check();
		return;
	}
	__builtin_unreachable();
}
int main(){
//	freopen("106197F_input.txt","r",stdin);
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
