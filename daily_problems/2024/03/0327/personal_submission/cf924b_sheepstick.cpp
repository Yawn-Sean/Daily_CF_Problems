#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, ub; cin >> n >> ub;

	vector<int> a(n);
	for (auto &ai : a){
		cin >> ai;
	}

	double res = -1;
	for (int i = 0; i < n - 1; i++){
		if (a[i + 1] - a[i] > ub) continue;
		int idx = (upper_bound(a.begin(), a.end(), ub + a[i]) - a.begin()) - 1;
		//cout << i <<" "<< idx << "---\n";
		if (idx > i + 1) res = max(res, 1 - (double)(a[i + 1] - a[i]) / (a[idx] - a[i]));
	}
	if (res < 0){
		cout << "-1\n";
	}
	else cout << fixed << setprecision(15) << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}