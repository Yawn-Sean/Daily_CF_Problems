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

void solve(){
	int n; cin>>n;
	vector<ai2>a(n),b;
	b.reserve(n/4);
	for(auto& [l,r]:a){
		cin>>l;
		r=l;
	}
	LL ans=0;
	while(a.size()>1){
		n=(int)(a.size());
		for(int i=0;i<n;i+=4){
			vector<int>v; v.reserve(8);
			for(int j=0;j<4;++j){
				v.emplace_back(a[i+j][0]);
				v.emplace_back(a[i+j][1]);
			}
			sort(all(v));
			v.erase(unique(all(v)),v.end());
			const int m=(int)(v.size());
			vector<LL>res_v(m);
			for(int k=0;k<m;++k){
				const int pivot=v[k];
				for(int j=0;j<4;++j){
					const auto& [l,r]=a[i+j];
					if(l<=pivot && pivot<=r);
					else if(r<pivot) res_v[k]+=pivot-r;
					else res_v[k]+=l-pivot; // l>pivot
				}
			}
			LL res=*min_element(all(res_v));
			int L=INT_MAX,R;
			for(int k=0;k<m;++k){
				if(res_v[k]==res){
					if(L==INT_MAX) L=v[k];
					R=v[k];
				}
			}
			assert(L!=INT_MAX);
			b.push_back({L,R});
			ans+=res;
		}
		swap(a,b);
		b.clear();
	}
	const auto& [l,r]=a[0];
	if(l<=0 && 0<=r);
	else ans+=min(abs(l),abs(r));
	cout<<ans<<"\n";
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
