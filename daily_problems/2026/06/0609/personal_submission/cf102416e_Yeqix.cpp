#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<array<i64, 5>> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
		f[i][4] = i + 1;
	}

	sort(f.begin(), f.end(), [&](auto x, auto y) {
		return x[3] > y[3];
	});

	auto get = [&](int i, int j)->bool{
		auto [x1, y1, z1, r1, id1] = f[i];
		auto [x2, y2, z2, r2, id2] = f[j];
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= (3 * r2 - r1) * (3 * r2 - r1);
	};

	vector<int> idx(n);
	for (int i = 0; i < n; i++) {
		idx[i] = f[i][4];
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int x = 1;
		for (const auto& v : ans) {
			if (get(i, v)) {
				x = 0;
				break;
			}
		}
		if (x) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for (const auto& v : ans) {
		cout << idx[v] << " ";
	}
	return 0;
}