int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n);
	for (auto &x : c) {
		cin >> x;
		x --;
	}
	DSU dsu(n);
	int l, r;
	for (int i = 0; i < m; i ++){
		cin >> l >> r;
		l --; r --;
		dsu.merge(l, r);
	}
	vector<unordered_map<int, int>> block_color(n);
	vector<int> most(n);
	for (int i = 0; i < n; i ++){
		int j = dsu.find(i);
		block_color[j][c[i]] ++;
		most[j] = max(most[j], block_color[j][c[i]]);
	}
	int ans = 0;
	for (int i = 0; i < n; i ++){
		if (i == dsu.find(i)){
			ans += dsu.size(i) - most[i];
		}
	}
	cout << ans << endl;
	return 0;
}
