#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, r; cin >> n >> r;
	vector<int> x(n);
	for (auto &xi : x){
		cin >> xi;
	}
	vector<double> y(n, r);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++) if (abs(x[i] - x[j]) <= 2 * r){
			y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
		}
	}
	for (int i = 0; i < n; i++){
		cout << fixed << setprecision(10) << y[i] << " \n"[i == n - 1];
	}


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}