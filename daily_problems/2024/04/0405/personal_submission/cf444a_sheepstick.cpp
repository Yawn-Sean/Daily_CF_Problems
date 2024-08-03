#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (auto &ai : a) cin >> ai;
	double res = 0;
	while(m--){
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		res = max(res, (double) (a[u] + a[v]) / w);
	}
	cout << fixed << setprecision(15) << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}