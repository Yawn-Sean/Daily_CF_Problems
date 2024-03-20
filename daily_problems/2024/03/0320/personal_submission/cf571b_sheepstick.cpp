#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1LL << 55;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	sort(a.begin(), a.end());

	int q = n / k;
	int rem = n - q * k;

	//large groups of (n / k + 1) size
	vector<i64> dp(rem + 1, INF);
	
	dp[0] = 0;
	for (int i = 0; i < k; i++){
		for (int j = rem; j >= 0; j--){
			if (j < rem) {
				//a[iq + j] to a[(i + 1)q + j]
				dp[j + 1] = min(dp[j + 1], dp[j] + a[(i + 1) * q + j] - a[i * q + j]);
			}
			//a[iq + j] to a[(i + q)q + (j - 1)]
			dp[j] += a[(i + 1) * q + j - 1] - a[i * q + j];
		}
	}
	cout << dp[rem] << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}
