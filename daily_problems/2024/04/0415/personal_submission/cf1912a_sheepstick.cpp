#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1LL << 50;
using pi = array<i64,3>;
void solve() {
	i64 x; cin >> x;
	int k; cin >> k;

	vector<vector<i64>> a(k);
	for (int i = 0; i < k; i++){
		int len; cin >> len;
		a[i].resize(len);
		for (int j = 0; j < len; j++){
			cin >> a[i][j];
		}
	}

	//calculate  min_low_gap, delta;
	vector<vector<pi>> dp(k); 
	for (int i = 0; i < k; i++){
		i64 cur = 0, mi = INF;
		for (int j = 0; j < (int) a[i].size(); j++){
			cur += a[i][j];
			mi = min(mi, cur);
			if (cur >= 0){
				dp[i].push_back({mi, cur});
				cur = 0;
				mi = INF;
			}
		}
	}
	
	priority_queue<array<i64,4>> pq;
	for (int i = 0; i < k; i++){
		if (!dp[i].empty()) pq.push({dp[i][0][0], dp[i][0][1], 0, i});
	}

	while(!pq.empty()){
		auto [gap, delta, edPos, belong] = pq.top(); pq.pop();
		if (x + gap >= 0){
			x += delta;
			if (edPos < (int) dp[belong].size() - 1){
				pq.push({dp[belong][edPos + 1][0], dp[belong][edPos + 1][1], edPos + 1, belong});				
			}
		}
		else break;
	}
	cout << x << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}