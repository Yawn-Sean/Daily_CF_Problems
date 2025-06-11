#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		input:input.txt
		output:output.txt
	*/
	ifstream input("input.txt");
	
	int n, a, b;
	input >> n >> a >> b;
	// cin >> n >> a >> b;
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		input >> arr[i];
		// cin >> arr[i];
	}
	input.close();
	
	if (a > b) { swap(a, b); }
	
	// i位置 选择a/b颜色 消耗a颜色的量=x的最小差距
	// dp[i+1][a][x+arr[i+1]] = dp[i][a][x]
	// if arr[i+1] <= b_left(= tot - x) 
	// dp[i+1][b][x] 
	
	vector<vector<int>> dp(2, vector<int>(a + 1, inf));
	int tot = 0, last = 0;
	dp[0][0] = dp[1][0] = 0;
	
	for (int i = 0; i < n; i++) {
		tot += arr[i];
		vector<vector<int>> ndp(2, vector<int>(a + 1, inf));
		
		// 前一个选择j颜色
		for (int j = 0; j <= 1; j++) {
			// 后一个选择k颜色
			for (int k = 0; k <= 1; k++) {
				// 至少上一次的起点是...
				for (int x = a; x >= 0; x--) {
					if (j == k) {
						if (j == 0){ // a颜色 
							if (x + arr[i] <= a) {
								ndp[j][x + arr[i]] = min(ndp[j][x + arr[i]], dp[k][x] + 0);							
							}
						} else {
							int b_used = (tot - x);
							if (b_used <= b) {
								ndp[j][x] = min(ndp[j][x], dp[k][x] + 0);
							}
						}
					} else {
						if (j == 0) {
							if (x + arr[i] <= a) {
								ndp[j][x + arr[i]] = min(ndp[j][x + arr[i]], dp[k][x] + min(arr[i], last));
							}
						} else {
							int b_used = (tot - x);
							if (b_used <= b) {
								ndp[j][x] = min(ndp[j][x], dp[k][x] + min(arr[i], last));							
							}
						}
					}
				}
			}	
		}
		last = arr[i];
		swap(dp, ndp);
	}
	
	int ans = inf;
	for (int x = 0; x <= a; x++){
		ans = min(ans, min(dp[0][x], dp[1][x]));
	}
	ofstream output("output.txt");
	output << (ans == inf ? -1 : ans);
	output.close();
	// cout << (ans == inf ? -1 : ans);
	return 0;
}
