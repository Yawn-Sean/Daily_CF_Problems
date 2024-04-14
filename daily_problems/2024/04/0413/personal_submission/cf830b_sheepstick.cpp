#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1E5 + 5;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<set<int>> pos(M);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]].insert(i);
	}
	sort(a.begin(), a.end());

	int idx = 0;
	i64 res = 0;
	for (int i = 0; i < n; i++){
		auto it = pos[a[i]].lower_bound(idx);
		if (it == pos[a[i]].end()){
			res += n - i;
			idx = 0;
			it = pos[a[i]].lower_bound(idx);
		}
		idx = *it;
		pos[a[i]].erase(it);

	}
	res += n;
	cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}