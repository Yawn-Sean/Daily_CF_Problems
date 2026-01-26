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
	int n,m;
	cin>>n>>m;
	vector<int>cnt,_real;
	cnt.reserve(n*m);
	_real.reserve(n*m);
	{
		vector<int>a(n*m);
		for(auto& x:a) cin>>x;
		sort(all(a));
		cnt.emplace_back(0);
		_real.emplace_back(a[0]);
		for(auto x:a){
			if(x==_real.back()) ++cnt.back();
			else{
				cnt.emplace_back(1);
				_real.emplace_back(x);
			}
		}
	}
	const int tot=int(cnt.size());
	vector<int>sum(tot+1);
	for(int i=1;i<=tot;++i){
		sum[i]=sum[i-1]+cnt[i-1];
	}
	auto get=[&](const int l,const int r)->int { // 0-based index
		return sum[r+1]-sum[l];
	};
	#ifdef LOCAL
	{
		auto __cnt=cnt;
		dbg(_real);
		dbg(__cnt);
	}
	#endif
	vector ans(n,vector<int>(m));
	for(int i=0;i<n;++i){
		int rest_pre=i,pt=0,used=0;
		for(int j=0;j<m;++j){
			auto work=[&]()->bool {
				if(cnt[pt]-used>=rest_pre+1){
					ans[i][j]=_real[pt];
					if((used+=rest_pre+1)==cnt[pt]){
						++pt,used=0;
					}
					return 1;
				}
				return 0;
			};
			if(work()) continue;
			{
				const int sub=cnt[pt]-used;
				rest_pre-=sub;
				++pt,used=0;
			}
			assert(!used);
			{
				int l=pt,r=tot-1,mid,opt=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(get(pt,mid)>=rest_pre+1){
						opt=mid;
						r=mid-1;
					}
					else l=mid+1;
				}
				assert(opt!=-1);
				const int sub=get(pt,opt-1);
				rest_pre-=sub;
				pt=opt;
			}
			assert(work());
		}
	}
	for(auto& v:ans){
		for(auto x:v) cout<<x<<' ';
		cout<<'\n';
	}
	return 0;
}
