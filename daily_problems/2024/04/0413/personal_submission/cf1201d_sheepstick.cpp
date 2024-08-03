#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1LL << 60;
void solve() {
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<int> L(n, m), R(n, -1), col(q);
	L[0] = R[0] = 0;
	for (int i = 0; i < k; i++){
		int x, y; cin >> x >>  y;
		x--; y--;
		L[x] = min(L[x], y);
		R[x] = max(R[x], y);
	}
	for (auto &ci : col){
		cin >> ci;
		ci--;
	}
	sort(col.begin(), col.end());
	vector dp(n, vector<i64>(2, INF)); //[left/right end]
	dp[0][0] = 2 * R[0];
	dp[0][1] = R[0];

	int row = 0;
	for (int i = 1; i < n; i++){
		if (L[i] < m){
			vector<int> a{L[row], R[row]};
			for (int j = 0; j < 2; j++){
				i64 preCost = dp[row][j];
				//nearest exit
				if (a[j] >= col[0]){
					auto it = upper_bound(col.begin(), col.end(), a[j]);
					it--;
					dp[i][0] = min(dp[i][0], preCost + R[i] - L[i] + abs(a[j] - *it) + abs(*it - R[i]));
					dp[i][1] = min(dp[i][1], preCost + R[i] - L[i] + abs(a[j] - *it) + abs(*it - L[i])); 
				}
				if (a[j] <= col[q - 1]){
					auto it = lower_bound(col.begin(), col.end(), a[j]);
					dp[i][0] = min(dp[i][0], preCost + R[i] - L[i] + abs(a[j] - *it) + abs(*it - R[i]));
					dp[i][1] = min(dp[i][1], preCost + R[i] - L[i] + abs(a[j] - *it) + abs(*it - L[i])); 
				}
			}
			row = i;
		}
	}
	i64 res = min(dp[row][0], dp[row][1]) + row;
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}