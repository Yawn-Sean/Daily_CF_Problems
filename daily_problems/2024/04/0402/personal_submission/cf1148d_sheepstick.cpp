#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<array<int,3>> inc, dec;
	for (int i = 1; i <= n; i++){
		int l, r; cin >> l >> r;
		if (l < r) inc.push_back({r, l, i});
		else dec.push_back({r, l, i});
	}

	//increasing
	sort(inc.rbegin(), inc.rend());
	
	vector<int> a;
	int last = INT_MAX;
	for (auto [r, l, i] : inc){
		if (l < last){
			a.push_back(i);
			last = r;
		}
	}

	sort(dec.begin(), dec.end());
	vector<int> b;
	last = INT_MIN;
	for (auto [r, l, i] : dec){
		if (l > last){
			b.push_back(i);
			last = r;
		}
	}
	if ((int) b.size() > (int) a.size()) swap(a, b);
	cout << (int) a.size() << "\n";
	for (auto v : a){
		cout << v << " ";
	}
	cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}