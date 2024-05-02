#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
using namespace std;


vector<int> a;
int n,m;
bool ck(int times) {
	int lst = 0;
	int ok = 1;
	for (int i = 0;i < a.size();++i) {
		if (a[i] <= lst) {
			if (times < lst - a[i]) {
				ok = 0;
				break;
			}
		}
		else if (a[i] > lst) {
			int nd = m - a[i] + lst;
			if (times < nd) {
				lst = a[i];
			}
		}
	}
	return ok;
}


int main() {
	cin >> n >>m;

	for (int i = 0;i < n;++i) {
		int v;cin >> v;
		a.push_back(v);
	}

	int lo = 0;
	int hi = m - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (ck(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo;










	return 0;
}