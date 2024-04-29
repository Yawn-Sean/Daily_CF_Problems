#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, k; cin >> n >> k;
	cout << "? ";
	for (int i = 1;i <= k;++i) {
		cout << i << " ";
	}
	cout << endl;
	int p, v;cin >> p >> v;
	int same = 0;
	for (int i = 1;i <= k; ++i) {
		if (i == p) {
			continue;
		}
		cout << "? ";
		for (int j = 1;j <= k;++j) {
			if (j == i) {
				continue;
			}
			cout << j << " ";
		}
		cout << (k + 1) << endl;
		int p1, v1;cin >> p1 >> v1;
		if (p1 == p) {
			same++;
		}
	}
	cout << "? ";
	for (int i = 1; i <= k; ++i) {
		if (i == p) {
			continue;
		}
		cout << i << " ";
	}
	cout << (k + 1) << endl;
	int p1, v1;cin >> p1 >> v1;

	if (v1 > v) {
		cout << "! " << (k - same) << endl;
	}
	else {
		cout << "! " << (same + 1) << endl;
	}
	




	return 0;
}