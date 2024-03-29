#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	int ones = count(a.begin(), a.end(), 1);
	if (ones){
		cout << n - ones << "\n";
		return;
	}

	int res = INT_MAX;
	for (int i = 0; i < n; i++){
		int j = i, g = a[i];
		while(j < n - 1 && g > 1){
			g = gcd(g, a[++j]);
		}
		if (g == 1) res = min(res, j - i + n - 1);
	}
	if (res == INT_MAX) res = -1;
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}