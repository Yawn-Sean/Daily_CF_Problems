#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<i64> b(n);
	for (auto &bi : b){
		cin >> bi;
	}
	const int M = 60;
	vector<vector<i64>> a(M);
	for (int i = 0; i < n; i++){
		int y = __builtin_ctzll(b[i]);
		a[y].push_back(b[i]);
	}
	for (int i = 0; i < M - 1; i++){
		if ((int) a[i].size() > (int) a[i + 1].size()) swap(a[i], a[i + 1]);
	}
	cout << n - (int) a[M - 1].size() << "\n";

	for (int i = 0; i < M - 1; i++){
		for (auto v : a[i]){
			cout << v <<" ";
		}
	}
	cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}