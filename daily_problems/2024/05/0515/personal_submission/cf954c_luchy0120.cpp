#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;



int main() {
	int n;cin >> n;

	int x = 1e9;
	int y = 1e9;
	vector<int> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	for (int i = 1;i < n;++i) {
		if (abs(a[i] - a[i - 1]) > 1) {
			if (y == 1e9) {
				y = abs(a[i] - a[i - 1]);
			}
			else if (y != abs(a[i] - a[i - 1])) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else if (abs(a[i] - a[i - 1]) == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	int fx = (a[0] - 1) / y;
	int fy = (a[0] - 1) % y;
	for (int i = 1;i < n;++i) {
		if (a[i] - a[i - 1] == 1) {
			fy++;
		}
		else if (a[i] - a[i - 1] == -1) {
			fy--;
		}
		else if (a[i] - a[i - 1] == y) {
			fx++;
		}
		else {
			fx--;
		}
		if (fy >= y || fx < 0 || fy < 0) {
			cout << "NO";
			return 0;
		}
	}




	cout << "YES" << endl;
	cout << x << " " << y;




	return 0;
}