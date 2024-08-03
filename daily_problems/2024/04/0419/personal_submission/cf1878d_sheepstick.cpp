#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> l(k), r(k);
    for (auto &li : l) cin >> li;
    for (auto &ri : r) cin >> ri;
    int q; cin >> q;
	
	vector<int> rev(n + 2, 0);
	while(q--){
		int x; cin >> x;
		auto idx = upper_bound(l.begin(), l.end(), x) - l.begin() - 1;
		int L = l[idx], R = r[idx];
		int a = min(x, L + R - x), b = max(x, L + R - x);
		rev[a] ^= 1;
		rev[b + 1] ^= 1;
	}
	string res(n, ' ');
	for (int i = 0, j = 0; i < n; i++){
		if (i + 1 > r[j]) j++;
		rev[i + 1] ^= rev[i];
		if (rev[i + 1]) res[l[j] + r[j] - (i + 1) - 1] = s[i];
		else res[i] = s[i];
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}