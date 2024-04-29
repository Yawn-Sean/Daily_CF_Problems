#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	//check from left and right
	vector<int> L(n, 1 << 30), R(n, 1 << 30);
	for (int i = 0, j = 1; i < n; i++){
		j = min(j, a[i]);
		L[i] = j++;
	}
	for (int i = n - 1, j = 1; i >= 0; i--){
		j = min(j, a[i]);
		R[i] = j++;
	}
	int res = 0;

	for (int i = 0; i < n; i++){
		res = max(res, min(L[i], R[i]));
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}