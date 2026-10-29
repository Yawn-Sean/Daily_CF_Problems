#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using PII=pair<int,int>;
const int inf = 2e9;
//

void solve() {
	int n;
	cin>>n;
	int mxx=-inf,mnx=inf,mxy=-inf,mny=inf;
	map<PII,int>vis;
	int x,y;
	for(int i=1;i<=n;++i){
		cin>>x>>y;
		vis[make_pair(x,y)]=1;
		mxx=max(mxx,x),mnx=min(mnx,x);
		mxy=max(mxy,y),mny=min(mny,y);
	}
	if(vis[{mxx,mxy}] and vis[{mxx,mny}] and vis[{mnx,mxy}] and vis[{mnx,mny}]){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}