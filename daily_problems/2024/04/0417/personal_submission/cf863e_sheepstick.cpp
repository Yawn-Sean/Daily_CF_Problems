//https://codeforces.com/problemset/submission/863/256986985
void solve() {
	int n; cin >> n;
	vector<array<int,2>> dur(n);
	vector<int> pos;
	for (int i = 0; i < n; i++){
		cin >> dur[i][0] >> dur[i][1];
		for (int j = -1; j <= 1; j += 2){
			pos.push_back(dur[i][0] + j);
			pos.push_back(dur[i][1] + j);
		}
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	int sz = pos.size();

	vector<Info> x(sz, Info(0));
	LazySegmentTree<Info, Tag> seg(x);

	for (int i = 0; i < n; i++){
		dur[i][0] = lower_bound(pos.begin(), pos.end(), dur[i][0]) - pos.begin();
		dur[i][1] = lower_bound(pos.begin(), pos.end(), dur[i][1]) - pos.begin();
		seg.rangeApply(dur[i][0], dur[i][1] + 1, Tag(1));
	}

	for (int i = 0; i < sz; i++){
		auto x = seg.rangeQuery(i, i + 1).cnt;
		if (x == 0) seg.modify(i, Info(INF));
	}

	for (int i = 0; i < n; i++){
		seg.rangeApply(dur[i][0], dur[i][1] + 1, Tag(-1));
		auto x = seg.rangeQuery(0, sz).cnt;
		if (x) {
			cout << i + 1 << "\n";
			return;
		}
		seg.rangeApply(dur[i][0], dur[i][1] + 1, Tag(1));
	}
	cout << "-1\n";
}