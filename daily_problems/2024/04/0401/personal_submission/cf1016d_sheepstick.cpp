#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> r(n), c(m);

	int v = 0;
	for (auto &ri : r){
		cin >> ri;
		v ^= ri;
	}
	for (auto &ci : c){
		cin >> ci;
		v ^= ci;
	}
	if (v){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	for (int i = 0; i < n - 1; i++){
		cout << r[i] << " ";
		c[0] ^= r[i];
		for (int j = 1; j < m; j++){
			cout << 0 << " \n"[j == m - 1];
		}
	}
	for (int j = 0; j < m; j++){
		cout << c[j] << " \n"[j == m - 1];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}