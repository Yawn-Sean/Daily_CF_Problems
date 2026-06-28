#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i]) b.push_back(i);
	}
	ll ans = 0;
	for(int i = 1,x,y,lx,ry; i < b.size(); ++i){
		x = b[i - 1],y = b[i];
		if(min(a[x],a[y]) == 1 && max(a[x],a[y]) <= 2){
			lx = i >= 2 ? b[i - 2] : -1;
			ry = i + 1 < b.size() ? b[i + 1] : n;
			ans += 1ll * (x - lx) * (ry - y);
			if(y == x + 1) ans -= 1;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}