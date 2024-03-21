#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1LL << 60;
const int D = 30;
void solve() {
	int n, v; cin >> n >> v;
	vector<i64> a(30, INF);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 1; i < D; i++) if (a[i] > 2 * a[i - 1]){
		a[i] = 2 * a[i - 1];
	}
	for (int i = D - 2; i >= 0; i--) if (a[i] > a[i + 1]){
		a[i] = a[i + 1];
	}

	i64 cur = 0;
	for (int i = 0; i < D; i++){
		if (cur > a[i]) cur = a[i];
		if ((v >> i) & 1) cur += a[i];
	}
	cout << cur << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}