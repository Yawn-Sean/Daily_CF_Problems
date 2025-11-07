#include <bits/stdc++.h>

const int N = 1003;
int n, m; 
long long a[N];

struct Ask {
	int l, r;
	long long A, B;
} ask[N];

std::vector<std::pair<int, long long>> e[N];

void add(int a, int b, long long c) {
	e[a].push_back({b, c});
}

bool spfa() {
	std::vector<long long> dist(n + 1, 1e18);
	std::vector<int> vis(n + 1), cnt(n + 1);
	std::queue<int> q;
	q.push(0);
	dist[0] = 0;
	vis[0] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (auto &[y, w] : e[x]) {
			if (dist[y] > dist[x] + w) {
				dist[y] = dist[x] + w;
				cnt[y] = cnt[x] + 1;
				if (cnt[y] >= n + 1) return true;
				if (!vis[y]) {
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	return false;
}

bool check(long long mid) {
	for (int i = 0; i <= n; i++) e[i].clear();

	for (int i = 1; i <= n; i++) {
		add(i, i - 1, -(a[i] - mid));   // s[i] - s[i-1] >= a[i] - mid
		add(i - 1, i, a[i] + mid);      // s[i] - s[i-1] <= a[i] + mid
		add(i, i - 1, -1);              // s[i] - s[i-1] >= 1
	}
	for (int i = 1; i <= m; i++) {
		auto &[l, r, A, B] = ask[i];
		add(r, l - 1, -A);              // s[r] - s[l-1] >= A
		add(l - 1, r, B);               // s[r] - s[l-1] <= B
	}
	return spfa() == 0;
}

void soviet() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> ask[i].l >> ask[i].r >> ask[i].A >> ask[i].B;
	}

	long long l = 0, r = 1e13;
	long long ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	int T = 1; std::ios::sync_with_stdio(false); std::cin.tie(0);
//	std::cin >> T;
	while (T--) { soviet(); }
	return 0;
}
