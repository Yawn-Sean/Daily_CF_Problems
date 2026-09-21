#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &a : arr) cin >> a;
	sort(arr.begin(),arr.end());
	ll ans = 0;
	for(int i = 0,l,r; i < n - 1; i += (n - i) / 2){
		l = i;
		r = n - 1;
		while(l < r){
			ans += arr[r] - arr[l];
			l++;
			r--;
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