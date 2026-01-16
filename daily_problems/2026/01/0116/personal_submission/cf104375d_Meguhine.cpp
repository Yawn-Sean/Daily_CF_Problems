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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,Q;
	cin>>n>>Q;
	vector<int>a(n);
	for(auto& x:a) cin>>x;
	sort(all(a));
	a.reserve(a.size()+Q);
	for(int op,x,y;Q--;){
		cin>>op>>x;
		if(op==1){
			if(x>a.back()){
				a.emplace_back(x);
			}
			else{
				int p=lower_bound(all(a),x)-a.begin();
				if(a[p]!=x){
					p=upper_bound(all(a),x)-a.begin();
					a[p]=x;
				}
			}
			dbg(a);
		}
		else{
			cin>>y;
			const int l=lower_bound(all(a),x)-a.begin();
			const int r=upper_bound(all(a),y)-a.begin();
			cout<<(r-l)<<'\n';
		}
	}
	return 0;
}
