#include<bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;

ll pw[15] = {1}, ans, a[N];
int n, k;
unordered_map<int, unordered_map<int, int>> mp;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> k;
	
	for(int i = 1; i <= 10; ++ i) {
		pw[i] = pw[i - 1] * 10 % k;
	}
	
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		ll tmp = a[i] % k;
		for(int i = 1; i <= 10; ++ i) {
			tmp = tmp * 10 % k;
			++ mp[i][tmp];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		ll tmp = 1, len = 0;
		while(tmp <= a[i]) {
			tmp *= 10;
			++ len;
		}
		ans += mp[len][(k - a[i] % k) % k];
		if((tmp % k * a[i] + a[i]) % k == 0) {
			-- ans;
		}
	} 
	cout << ans;
	return 0;
}
