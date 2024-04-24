#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 1 << 30;

void solve() {
	int n; cin >> n;
	vector<array<int,3>> a(n);

	int redTot = 0;
	vector<int> redCnt(1 << n, 0), blueCnt(1 << n, 0);
	for (int i = 0; i < n; i++){
		char x; cin >> x;
		int r, b; cin >> r >> b;
		if (x == 'R') {
			a[i] = {0, r, b};
			redCnt[1 << i]++;
		}
		else {
			a[i] = {1, r, b};
			blueCnt[1 << i]++;
		}
		redTot += r;
	}

	for (int i = 1; i < 1 << n; i++){
		int lastBit = i & (-i);
		redCnt[i] = redCnt[i - lastBit] + redCnt[lastBit];
		blueCnt[i] = blueCnt[i - lastBit] + blueCnt[lastBit];
	}


	//f(i, mask): minimum cost when buy mask items and save i red coins.
	const int M = 121;
	vector<vector<int>> dp(M, vector<int>(1 << n, INF));
	dp[0][0] = 0;

	for (int i = 0; i < M; i++){
		for (int mask = 0; mask < 1 << n; mask++) if (dp[i][mask] < INF){
			for (int j = 0; j < n; j++) if (!(mask & (1 << j))){
				int save = i + min(redCnt[mask], a[j][1]);
				dp[save][mask | 1 << j] = min(dp[save][mask | 1 << j], dp[i][mask] + max(0, a[j][2] - blueCnt[mask]));
			}
		}
	}
	int res = INF;
	for (int i = 0; i < M; i++){
		if (dp[i][(1 << n) - 1] < INF){
			res = min(res, max(redTot - i, dp[i][(1 << n) - 1]));
		}
	}
	cout << res + n << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}