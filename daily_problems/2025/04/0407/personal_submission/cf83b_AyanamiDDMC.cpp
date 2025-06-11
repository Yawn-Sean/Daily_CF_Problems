#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n;
LL k;
int w[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	LL sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		sum += w[i];
	}

	if (sum < k) {
		cout << -1 << "\n";
		return 0;
	}

	// 二分查找最大的 m 使得 sum(min(a_i, m)) <= k
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		LL val = 0;
		for (int i = 0; i < n; ++i) val += min(w[i], mid);
		if (val <= k) l = mid;
		else r = mid - 1;
	}

	// 对剩余的k进行队列模拟
	deque<int> q;
	for (int i = 0; i < n; ++i) {
		if (w[i] > l) q.push_back(i);
		k -= min(w[i], l);
		w[i] -= min(w[i], l);
	}

	while (k && !q.empty()) {
		int u = q.front();
		q.pop_front();
		w[u]--;
		if (w[u] > 0) q.push_back(u);
		k--;
	}

	while (!q.empty()) {
		cout << q.front() + 1 << " ";
		q.pop_front();
	}
	cout << "\n";
	return 0;
}
