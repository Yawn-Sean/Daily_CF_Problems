#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	string n;
	cin >> n;
	int m = n.size();

	vector<int> nums(m * 3);
	for(int i = 0; i < m; ++i) nums[i] = n[i] - '0';
	for(int i = 1; i < m * 3; ++i) nums[i] += nums[i - 1];

	int carry = 0;
	for(int i = 0; i < m * 3; ++i){
		nums[i] += carry;
		carry = nums[i] / 10;
		nums[i] %= 10;
	}
	cout << nums.back();
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