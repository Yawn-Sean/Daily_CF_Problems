#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 1ll * n * (n + 1) / 2;
		return 0;
	}
	/*
		首先把k进行一波分解
		然后每个a[i]也分解成因子
		维护右枚举左 双指针一下就行
		对于更靠右侧的端点 左端点的可行范围是单调不减的
	*/
	
	vector<int> primes(51), kcnt(51);
	int idx = 0;
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0) {
			primes[++idx] = i;
			while (k % i == 0) {
				k /= i;
				++kcnt[idx];
			}
		}
	}

	if (k > 1) {
		primes[++idx] = k;
		++kcnt[idx];
	}
	
	vector<int> a(n);
	vector<vector<int>> acnt(n, vector<int>(51));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= idx; j++) {
			while (a[i] % primes[j] == 0) {
				a[i] /= primes[j];
				++acnt[i][j];
			}
		}
	}

	int l = 0, r = 0;
	i64 ans = 0;
	vector<int> cnt(51);
	
	auto check = [&]() {
		for (int j = 1; j <= idx; j++) {
			if (kcnt[j] > cnt[j]) { return false; }	
		}
		return true;
	};
		
	// 对于更大的l端点 r也需要更靠右才能满足答案
	while (l < n) {
		while (r < n and not check()) {
			for (int j = 1; j <= idx; j++) {
				cnt[j] += acnt[r][j];
			}
			r += 1;
		}
		
		if (not check()) { break; }
		ans += (n - r + 1);
		// cout << "Find " << l << ' ' << r << '\n';
		
		for (int j = 1; j <= idx; j++) {
			cnt[j] -= acnt[l][j];
		}
		l += 1;
	}
	cout << ans;
	return 0;
}
