#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> nums(n + 1), vals(n + 1);
	/*
		Q(2) = 0
		a02^0 + a12^1 + ... = 0
		
		ai -> ai'
		数值变化 (ai' - ai) * 2^i
		
		|ai'|<=k 
		(a0+a1+...+ai-1) (ai+ai+1+...)后面的项整数部分
		只需要判断除法过程中结果是否超过2k
		超过就直接break
	*/
	for (int i = 0; i <= n; i++) {
		cin >> nums[i];
	}
	
	for (int i = 0; i < n; i++) {
		int x = (nums[i] + vals[i]) / 2;
		vals[i] = (nums[i] + vals[i]) % 2;
		vals[i + 1] += x;
	}
	vals[n] += nums[n];
	
	int idx = -1;
	for (int i = 0; i <= n; i++) {
		if (vals[i] != 0) {
			idx = i;
			break;
		}
	}
	
	i64 cur = 0;
	int ans = 0;
	for (int i = n; i >= 0; i--) {
		cur = cur * 2 + vals[i];
		if (abs(cur) > 2 * k) break;
		if (i <= idx and abs(nums[i] - cur) <= k and !(i == n and nums[i] == cur)) {
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
