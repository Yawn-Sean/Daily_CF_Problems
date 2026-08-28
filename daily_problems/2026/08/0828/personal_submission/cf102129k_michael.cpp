#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int mod = 1e9 + 7;
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	cout << (a[0] - a[1] + mod) % mod;
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