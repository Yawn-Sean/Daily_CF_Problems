#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	ll sum = 0L;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	ll ans = sum;
	if(n >= 2){
		ans ^= sum - a[0];
		ans ^= sum - a[n - 1];
	}
	if(n >= 3){
		ans ^= sum - a[0] - a[n - 1];
	}
	cout << ans << '\n';

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}