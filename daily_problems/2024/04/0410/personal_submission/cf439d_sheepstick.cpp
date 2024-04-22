#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	vector<array<int,2>> mixed;
	for (auto &ai : a){
		cin >> ai;
		mixed.push_back({ai, 0});
	}
	i64 bTot = 0;
	for (auto &bi : b){
		cin >> bi;
		bTot += bi;
		mixed.push_back({bi, 1});
	}
	sort(mixed.begin(), mixed.end());

	int aCnt = 0, bCnt = 0;

	i64 res = 1LL << 60, aCur = 0;
	for (int i = 0; i < n + m; i++){
		auto [val, belong] = mixed[i];
		if (belong == 1) {
			bCnt++;
			bTot -= val;
		}
		else {
			aCnt++;
			aCur += val;
		}	
		res = min(res, bTot - 1LL * (m - bCnt) * val + 1LL * aCnt * val - aCur);
	}
	cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}