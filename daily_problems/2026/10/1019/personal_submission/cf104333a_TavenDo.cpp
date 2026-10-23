#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
using LL=long long;
using PLL=pair<LL,LL>;

//
const LL MOD=1e9+7;

void solve() {
	int n;
	cin>>n;
	vector<LL>a(n+1),b(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	LL T=1;
	for(int i=1;i<n;++i){
		T=T*i%MOD;
	}
	LL res=0;
	int m=20;
	vector<PLL>pref(m+1);
	for(int i=1;i<=n;++i){
		int x=b[i];
		int k=1;
		for(int j=0;j<=m;++j){
			if(x&1){
				pref[j].fi=(pref[j].fi+k)%MOD;
			}else{
				pref[j].se=(pref[j].se+k)%MOD;
			}
			k*=2;
			x>>=1;
		}
	}
	for(int i=1;i<=n;++i){
		int x=a[i];
		for(int j=0;j<=m;++j){
			if(x&1){
				res=(res+pref[j].se)%MOD;
			}else{
				res=(res+pref[j].fi)%MOD;
			}
			x>>=1;
		}
	}
	cout<<res*T%MOD<<endl;
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