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
	int n; LL m;
	cin>>n>>m;
	--n;
	vector<LL>a(n);
	for(auto& x:a) cin>>x;
	auto work=[&](int i,int j,LL l,LL r)->int{
		LL mid=l+r>>1;
		auto it=upper_bound(a.begin()+i,a.begin()+j+1,mid);
		int k=-1;
		if(it!=a.end()) k=it-a.begin();
		if(it!=a.begin()){
			--it;
			if(k==-1) k=it-a.begin();
			else{
				int p=it-a.begin();
				if(llabs((r-a[p])-(a[p]-l))<llabs((r-a[k])-(a[k]-l))){
					k=p;
				}
			}
		}
		return k;
	};
	LL ans=1e18;
	for(int i=n-2;i>0;--i){
		/*
		choose i, [0,i-1] find one, [i+1,n-1] find one
		*/
		int j=work(0,i-1,0ll,a[i]);
		int k=work(i+1,n-1,a[i],m);
		array<LL,4>b{a[j],a[i]-a[j],a[k]-a[i],m-a[k]};
		dbg(j,i,k);
		sort(all(b));
		updmn(ans,b[3]-b[0]);
	}
	cout<<ans;
	return 0;
}
