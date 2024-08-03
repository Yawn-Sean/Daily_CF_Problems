#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	vector<vector<int>> full(n, vector<int>(n)), half(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			int mi = INT_MAX;
			for (int k = 0; k < m; k++){
				mi = min(mi, abs(grid[i][k] - grid[j][k]));
			}
			full[i][j] = full[j][i] = mi;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int mi = INT_MAX;
			for (int k = 0; k < m - 1; k++){
				mi = min(mi, abs(grid[i][k] - grid[j][k + 1]));
			}
			half[i][j] = mi;
		}
	}
	if (n == 1){
		cout << half[0][0] << "\n";
		return;
	}
	int res = 0;



	for (int i = 0; i < n; i++){
		//swap(full[i], full[n - 1]);
		//swap(half[i], half[n - 1]);

		auto idx = [&](int v) -> int {
			return v < i ? v : v + 1;
		};


		vector<vector<int>> dp(n - 1, vector<int>(1 << (n - 1), 0));
		for (int mask = 1; mask < 1 << (n - 1); mask++){
			for (int j = 0; j < n - 1; j++) if (mask & (1 << j)){
				if (mask == (1 << j)){ //starting pos
					//cout << mask <<" "<< j << " "<< full[n - 1][j] << "--\n";
					dp[j][mask] = full[i][idx(j)];
				}
				else {
					for (int k = 0; k < n - 1; k++) if (k != j && (mask & (1 << k))){
						dp[j][mask] = max(dp[j][mask], min(dp[k][mask ^ (1 << j)], full[idx(k)][idx(j)]));
					}
				}
			}
		}


		for (int j = 0; j < n - 1; j++){
			//cout << dp[i][(1 << (n - 1)) - 1] << "\n";
			res = max(res, min(half[idx(j)][i], dp[j][(1 << (n - 1)) - 1]));
		}
		//swap(full[i], full[n - 1]);
		//swap(half[i], half[n - 1]);
	}
	cout << res << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}