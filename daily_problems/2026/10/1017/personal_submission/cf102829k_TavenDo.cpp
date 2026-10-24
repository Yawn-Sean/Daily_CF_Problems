#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
using LL=long long;
using PLL=pair<LL,LL>;

//凸包视角：对于某一个边，其他所有点，都是跟这个边的逆时针顺序成逆时针，即叉积小于0
//即对于逆时针顺序AB，任意其他点C，AB与AC的叉积均<0
const int MOD=1e9+7;
LL qpow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1)res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}

void solve() {
	int n;
	cin>>n;
	vector<PLL>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i].fi>>a[i].se;
	}
	LL ans=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j){
				continue;
			}
			LL cnt=0,Ux=a[i].fi-a[j].fi,Uy=a[i].se-a[j].se;
			for(int k=1;k<=n;++k){
				if(k==i or k==j){
					continue;
				}
				LL Vx=a[i].fi-a[k].fi,Vy=a[i].se-a[k].se;
				if(Ux*Vy-Vx*Uy<0){
					++cnt;
				}
			}
			ans=(ans+qpow(2,cnt))%MOD;
		}
	}
	cout<<ans<<endl;
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