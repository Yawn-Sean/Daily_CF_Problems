#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &ai : a) {
		cin >> ai;
		ai--;
	}
	vector<int> f(4);
	for (auto &ai : a){
		f[0] += (ai == 0);
		f[1] = max(f[0], f[1] + (ai == 1));
		f[2] = max(f[1], f[2] + (ai == 0));
		f[3] = max(f[2], f[3] + (ai == 1));
	}
	cout << f[3] << "\n";




}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}