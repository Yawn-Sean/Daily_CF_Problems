int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	vector<int> lt(N, -1), rt(N, -1), cnt(N);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		cnt[x] += 1;
		if (lt[x] == -1) {
			lt[x] = rt[x] = i;
		} else {
			rt[x] = i;
		}
	}

	vector<tuple<int, int, int>> p;
	for (int i = 0; i < N; ++i) {
		if (cnt[i]) {
			p.emplace_back(lt[i], rt[i], cnt[i]);
		}
	}
	sort(p.begin(), p.end());

	vector<pair<int, int>> seg;
	int mx = 0;

	int ans = 0;
	for (auto [l, r, c] : p) {
		if (seg.empty() || l > seg.back().second) {
			if (!seg.empty()) {
				auto [x, y] = seg.back();
				ans += y - x + 1 - mx;
			}
			seg.emplace_back(l, r);
			mx = c;
		} else  {
			seg.back().second = max(seg.back().second, r);
			mx = max(mx, c);
		}
	}
	auto [x, y] = seg.back();
	ans += y - x + 1 - mx;

	cout << ans << "\n";

	return 0;
}
