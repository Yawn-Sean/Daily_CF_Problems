#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1E5 + 5;
void solve() {
    int n; cin >> n;
    vector<int> a(n), state(M, 0), cnt(M, 0);
    for (auto &ai : a) cin >> ai;

    int mx = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		cnt[state[a[i]]]--;
		state[a[i]]++;
		cnt[state[a[i]]]++;

		mx = max(mx, state[a[i]]);
		bool good = false;
		if (cnt[1] == i + 1 || cnt[i + 1] == 1) good = true;
		if (cnt[1] == 1 && cnt[mx] * mx == i) good = true;
		if (cnt[mx] == 1 && cnt[mx - 1] * (mx - 1) == i + 1 - mx) good = true;
		if (good) res = max(res, i + 1);

		// if (i == 12) {
		// 	cout << cnt[1] << " "<< cnt[3] << " "<< mx <<"---\n";
		// }
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}