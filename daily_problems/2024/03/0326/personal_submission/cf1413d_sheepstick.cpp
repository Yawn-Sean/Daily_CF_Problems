#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> stk; //[idx, lb]
	int j = 0;
	bool ok = true;
	vector<int> pos(n, 0);
	for (int i = 0; i < 2 * n; i++){
		char x; cin >> x;
		if (x == '+'){
			stk.push_back({j++, 0});
		}
		else {
			int y; cin >> y;
			if (stk.empty() || stk.back().second >= y){
				ok = false;
				continue;
			}
			auto [idx, _] = stk.back(); stk.pop_back();
			pos[idx] = y;
			if (!stk.empty()){
				stk.back().second = max(stk.back().second, y);
			}
		}
	}
	if (!ok){
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		for (int i = 0; i < n; i++){
			cout << pos[i] << " \n"[i == n - 1];
		}
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}