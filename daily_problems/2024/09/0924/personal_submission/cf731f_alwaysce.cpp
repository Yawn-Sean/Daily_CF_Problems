#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int M = 2e5 + 5;
	vector<int> nums(n), pre(M + 2, 0);
	for (auto& x: nums) {
		cin >> x;
		pre[x + 1]++;
	}
	
	for (int i = 0; i < M + 1; i++) {
		pre[i + 1] += pre[i];
	}
	
	vector<i64> ans(M + 1);
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= M; j += i) {
			ans[i] += 1ll * j * (pre[min(M + 1, j + i)] - pre[j]);
		}
	}
	
	i64 res = 0;
	for (auto& x: nums) {
		res = max(res, ans[x]);
	}
	cout << res;
    return 0;
}
