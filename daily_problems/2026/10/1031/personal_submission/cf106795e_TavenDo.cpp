#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
#define sz(x) (int)(x.size())
using LL=long long;
using PLL=pair<LL,LL>;
const LL inf = 1e18;

//

void solve() {
	int n,r;
	cin>>n>>r;
	vector<PLL>a(n+1);
	LL lim=-inf;
	for(int i=1;i<=n;++i){
		cin>>a[i].fi>>a[i].se;
		lim=max(lim,a[i].se+1);
	}
	sort(a.begin()+1,a.begin()+1+n);
	vector<LL>t;
	for(int i=2;i<=n;++i){
		t.push_back((a[i].fi-a[i-1].fi)*r+a[i-1].se-a[i].se);   //T中数字>=lim的最小公因数
	}
	if(t.empty()){
		cout<<lim<<endl;
		return;
	}
	sort(t.begin(),t.end(),greater());
	LL G=t[0];
	if(G==0){
		cout<<lim<<endl;
		return;
	}
	vector<LL>f;
	for(LL i=1;i*i<=G;++i){
		if(G%i){
			continue;
		}
		LL x=i,y=G/x;
		if(x>=lim){
			f.push_back(x);
		}
		if(y!=x and y>=lim){
			f.push_back(y);
		}
	}
	sort(f.begin(),f.end());
	for(int i=1;i<sz(t);++i){
		vector<LL>nf;
		for(auto &cur:f){
			if((t[i]%cur)==0){
				nf.push_back(cur);
			}
		}
		f.swap(nf);
	}
	if(f.empty()){
		cout<<-1<<endl;
	}else{
		cout<<f[0]<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}