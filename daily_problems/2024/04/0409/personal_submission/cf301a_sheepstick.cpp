//https://codeforces.com/contest/301/submission/255803537
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(2 * n - 1);

	int tot = 0;
	for (auto &ai : a){
		cin >> ai;
		tot += ai;
	}
	sort(a.begin(), a.end());
	int res = tot;

	if (n % 2 == 0){
		for (int i = 0; i < 2 * n - 2; i += 2){
			tot -= 2 * a[i];
			tot -= 2 * a[i + 1];
			res = max(res, tot);
		}
	}
	else {
		for (int i = 0; i < 2 * n - 1; i++){
			tot -= 2 * a[i];
			res = max(res, tot);
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