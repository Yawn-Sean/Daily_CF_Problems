#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[2010] {}, cnt[2010] {}, flg = 1;
vector<int> ed[2010];
vector<int> dfs(int u) {
	vector<int> ret;
	for (int v : ed[u]) {
		for (int x : dfs(v)) {
			ret.emplace_back(x);
		}
	}
	sort(ret.begin(), ret.end(), [&](int i, int j) {
		return ans[i] < ans[j];
	});
	if (ret.size() < cnt[u]) flg = 0;
	else {
		for (int i = 0; i < cnt[u]; i++) ans[ret[i]] = i + 1;
		ans[u] = cnt[u] + 1;
		for (int i = cnt[u]; i < ret.size(); i++) ans[ret[i]] = i + 2;
		ret.emplace_back(u);
	}
	return ret;
}
void yrlpSolve() {
	int n; cin >> n;
	int r = 0;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p >> cnt[i];
		if (!p) r = i;
		else ed[p].push_back(i);
	}
	dfs(r);
	if (!flg) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}

    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
