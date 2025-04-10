#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, x1, x2;
	cin >> n >> x1 >> x2;

	vector<int> w(n), order(n);
	for (auto &v: w) cin >> v;
	
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) { return w[i] < w[j]; });
	
	for (int i = 0; i < n; i++) {
		int c1 = (x1 + w[order[i]] - 1) / w[order[i]];
		if (i + c1 < n && 1ll * w[order[i + c1]] * (n - i - c1) >= x2) {
			cout << "Yes" << "\n";
			cout << c1 << ' ' << n - i - c1 << "\n";


			for (int idx = i; idx < i + c1; idx++) cout << order[idx] + 1 << " ";
			cout << "\n";

			for (int idx = i + c1; idx < n; idx++) cout << order[idx] + 1 << " ";
			cout << "\n";
			return 0;
		}


		int c2 = (x2 + w[order[i]] - 1) / w[order[i]];


		if (i + c2 < n && 1ll * w[order[i + c2]] * (n - i - c2) >= x1) {
			cout << "Yes" << "\n";
			cout << n - i - c2 << " " << c2 << "\n";
			
			for (int idx = i + c2; idx < n; idx++) cout << order[idx] + 1 << " ";
			cout << "\n";
			
			for (int idx = i; idx < i + c2; idx++) cout << order[idx] + 1 << " ";
			cout << "\n";
			return 0;
		}
	}
	
	cout << "No" << "\n";

	return 0;
}
