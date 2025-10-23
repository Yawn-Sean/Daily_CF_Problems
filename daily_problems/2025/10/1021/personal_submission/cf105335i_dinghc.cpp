#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (auto& x : a) {
		scanf("%d", &x);
	}
	vector<long long> ans(2);
	if (a[0] > a[1]) {
		ans[0] = a[0] - 1;
		ans[1] = a[1] - 1;
	} else {
		ans[0] = a[0] - 1;
		ans[1] = a[1] - 2;
	}
	ans[1] += 1LL * (n - 1) * n / 2;
	ans[0] = (ans[0] + ans[1] / (n - 1)) % n + 1;
	ans[1] = ans[1] % (n - 1) + 1;
	if (ans[1] >= ans[0]) ans[1] += 1;
	vector<int> vis(n + 1, 0);
	for (int i = 2; i < n; i++) {
		vis[a[i]] = 1;
	}
	vector<int> mapping(n + 1, 1);
	for (int i = 2, p = 1, q = 1; i < n; i++) {
		while (vis[p] == 0) p += 1;
		while (q == ans[0] || q == ans[1]) q += 1;
		mapping[p++] = q++;
	}
	printf("%lld %lld ", ans[0], ans[1]);
	for (int i = 2; i < n; i++) {
		printf("%d ", mapping[a[i]]);
	}
    return 0;
}

