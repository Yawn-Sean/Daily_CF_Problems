#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n * 2);
	vector<int> b(n * 2);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;

	ll ans = 0;
	priority_queue<ll> pq;
	for(int i = 0; i < n * 2; ++i){
		ans -= b[i];
		pq.push(a[i] + b[i]);
		if(i % 2 == 0){
			ans += pq.top();
			pq.pop();
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