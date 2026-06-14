#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	vector<int> o1(n), o2(n), o3(n), o4(n);

	iota(o1.begin(), o1.end(), 0);
	iota(o2.begin(), o2.end(), 0);
	iota(o3.begin(), o3.end(), 0);
	iota(o4.begin(), o4.end(), 0);

	sort(o1.begin(), o1.end(), [&] (int i, int j) {
		pair<int, int> pt1 = {pts[i].first, pts[i].second};
		pair<int, int> pt2 = {pts[j].first, pts[j].second};
		return pt1 < pt2;
	});

	sort(o2.begin(), o2.end(), [&] (int i, int j) {
		pair<int, int> pt1 = {pts[i].second, -pts[i].first};
		pair<int, int> pt2 = {pts[j].second, -pts[j].first};
		return pt1 < pt2;
	});

	sort(o3.begin(), o3.end(), [&] (int i, int j) {
		pair<int, int> pt1 = {-pts[i].first, -pts[i].second};
		pair<int, int> pt2 = {-pts[j].first, -pts[j].second};
		return pt1 < pt2;
	});

	sort(o4.begin(), o4.end(), [&] (int i, int j) {
		pair<int, int> pt1 = {-pts[i].second, pts[i].first};
		pair<int, int> pt2 = {-pts[j].second, pts[j].first};
		return pt1 < pt2;
	});

	vector<int> vis(n, 0);
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

	for (int i = 0; i < n / 4 - 1; i ++) {
		while (vis[o1[p1]]) p1 ++; vis[o1[p1]] = 1;
		while (vis[o2[p2]]) p2 ++; vis[o2[p2]] = 1;
		while (vis[o3[p3]]) p3 ++; vis[o3[p3]] = 1;
		while (vis[o4[p4]]) p4 ++; vis[o4[p4]] = 1;
	}

	vector<pair<int, int>> chosen;

	for (int i = 0; i < n; i ++) {
		if (!vis[i]) {
			chosen.emplace_back(pts[i]);
		}
	}

	auto [x1, y1] = chosen[0];
	auto [x2, y2] = chosen[1];
	auto [x3, y3] = chosen[2];

	int dx1 = x2 - x1, dy1 = y2 - y1;
	int dx2 = x3 - x1, dy2 = y3 - y1;

	cout << abs(1ll * dx1 * dy2 - 1ll * dy1 * dx2);

	return 0;
}