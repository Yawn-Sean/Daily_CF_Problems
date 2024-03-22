#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1E6 + 5;
void solve() {
	int n; cin >> n;
	vector<int> a(M);
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[x] = 1;
	}

	int res = 0;
	for (int i = 1; i < M; i++) if (a[i]){
		res = max(res, a[i]);
		for (int j = 2; i * j < M; j++){
			if (a[i * j]) {
				a[i * j] = max(a[i * j], a[i] + 1);
			}
		}
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}