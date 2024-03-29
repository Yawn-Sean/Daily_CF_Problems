#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<vector<int>> pos(8);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		pos[a[i]].push_back(i);
	}

	int res = 0;
	for (int i = 0; i < 8; i++) if (!pos[i].empty()){
		res++;
	}
	vector<int> pow3(9, 1);
	for (int i = 1; i <= 8; i++){
		pow3[i] = pow3[i - 1] * 3;
	}


	vector<vector<int>> vals(9); //categorize based on set bit of the base-3 values
	vector<int> state(pow3[8]);  //which bit are set

	//preprocessing
	int mask = 0, val = 0;
	auto dfs = [&](auto self, int i) -> void {
		//cerr << i <<"---\n";
		if (i == 8) {
			int cnt = __builtin_popcount(mask);
			vals[cnt].push_back(val);
			state[val] = mask;
			return;
		}
		// add 1 or 2
		mask ^= 1 << i;
		val += pow3[i];
		self(self, i + 1);
		val += pow3[i];
		self(self, i + 1);
		mask ^= 1 << i;
		val -= 2 * pow3[i];
		self(self, i + 1);
	};
	dfs(dfs, 0);

	auto findPos = [&](int stPos, int tar, int cnt) -> int {
		auto idx = upper_bound(pos[tar].begin(), pos[tar].end(), stPos) - pos[tar].begin();
		idx += cnt - 1;
		if (idx >= (int) pos[tar].size()) return n;
		else return pos[tar][idx];
	};
	
	for (int i = 1; i <= n / 8; i++){ //lb
		vector<vector<int>> dp(8, vector<int>(pow3[8], n));
		for (int j = 0; j < 8; j++){
			dp[j][pow3[j]] = findPos(-1, j, i);
			dp[j][2 * pow3[j]] = findPos(-1, j, i + 1);
		}
		for (int j = 1; j < 8; j++){ //set numbers
			for (auto val : vals[j]){
				for (int k = 0; k < 8; k++) if ((state[val] & (1 << k)) && (dp[k][val] < n)){
					for (int w = 0; w < 8; w++) if (!(state[val] & (1 << w))){
						dp[w][val + pow3[w]] = min(dp[w][val + pow3[w]], findPos(dp[k][val], w, i));
						dp[w][val + 2 * pow3[w]] = min(dp[w][val + 2 * pow3[w]], findPos(dp[k][val], w, i + 1));
					}
				}
			}
		}
		for (auto val : vals[8]){
			for (int k = 0; k < 8; k++) if (dp[k][val] < n){
				int cur = val, ans = 0;
				while(cur){
					ans += (cur % 3) - 1 + i;
					cur /= 3;
				}
				res = max(res, ans);
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