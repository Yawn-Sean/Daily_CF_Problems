#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<vector<int>> participants(n + 1);
	vector<int> mx(n + 1);
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		participants[x].push_back(y);
		mx[x] = y;
	}

	map<int,int> mp;
	for (int i = 1; i <= n; i++) if (mx[i]){
		mp[mx[i]] = i;
	}
	int q; cin >> q;
	while(q--){
		int k; cin >> k;
		vector<int> ban(k);
		for (auto &bi : ban){
			cin >> bi;
			if (mx[bi]){
				mp.erase(mx[bi]);
			}
		}
		if (mp.empty()){
			cout << "0 0\n";
		}
		else if ((int) mp.size() == 1){
			auto idx = mp.begin() -> second;
			cout << idx <<" "<< participants[idx][0] << "\n";
		}
		else {
			int largest = mp.rbegin() -> second; 
			auto second_largest = (next(mp.rbegin(), 1)) -> second;
			auto it = upper_bound(participants[largest].begin(), participants[largest].end(), participants[second_largest].back());
			cout << largest <<" "<< *it << "\n";
		}
		for (auto &bi : ban){
			if (mx[bi]){
				mp[mx[bi]] = bi;
			}
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}