#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//等差数列是平方级别增加，剪枝暴力

void solve() {
	LL n,k;
	cin>>n>>k;
	vector<LL>a(n+1);
	LL ans=k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		LL idx=i,tot=k;
		for(int j=0;j<=n;++j){
			idx+=j;
			if(idx>n){
				break;
			}
			tot+=a[idx];
			if(tot<0){
				break;
			}
			ans=max(ans,tot);
		}
	}
	cout<<ans<<endl;
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