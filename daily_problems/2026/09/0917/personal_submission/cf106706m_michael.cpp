#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto &num : nums) cin >> num;
	ll ans = 1ll * n * (n - 1) / 2 - 1;
	ll sum = 0;
	for(int i = 0,cur; i < n; ++i){
		cur = nums[i];
		ans = max(ans,sum - cur);
		sum += cur;
	}
	sum = 0;
	for(int i = n - 1,cur;i >= 0; --i){
		cur = nums[i];
		ans = max(ans,sum - cur);
		sum += cur;
	}
	cout << ans << "\n";
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