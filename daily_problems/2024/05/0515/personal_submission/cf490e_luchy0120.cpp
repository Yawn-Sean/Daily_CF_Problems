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
	vector<string> v(n);
	for (int i = 0;i < n;++i) {
		cin >> v[i];
	}
	if (v[0][0] == '?') {
		v[0][0] = '1';
	}
	for (int i = 1;i < v[0].size();++i) {
		if (v[0][i] == '?') {
			v[0][i] = '0';
		}
	}
	for (int j = 1;j < v.size();++j) {
		if (v[j].size() < v[j - 1].size()) {
			cout << "NO" << endl;
			return 0;
		}
		else if (v[j].size() > v[j - 1].size()) {
			if (v[j][0] == '?') {
				v[j][0] = '1';
			}
			for (int u = 1;u < v[j].size();++u) {
				if (v[j][u] == '?') {
					v[j][u] = '0';
				}
			}
		}
		else {
			int ok = 0;
			int lst = v[j].size() - 1;
			for (int i = 0;i < v[j - 1].size();++i) {
				if (v[j][i] == '?') {
					continue;
				}
				else if (v[j][i] > v[j - 1][i]) {
					for (int u = 0;u < v[j].size();++u) {
						if (v[j][u] == '?') {
							if (u < i) {
								v[j][u] = v[j - 1][u];
							}
							else {
								v[j][u] = '0';
							}
						}
					}
					ok = 1;
					break;
				}
				else if (v[j][i] < v[j - 1][i]) {
					lst = i;
					break;
				}
			}
			if (!ok) {
				int st = -1;
				for (int u = lst;u >= 0;--u) {
					if (v[j][u] == '?') {
						if (v[j - 1][u] != '9') {
							v[j][u] = v[j - 1][u] + 1;
							st = u;
							break;
						}
					}
				}
				if (st == -1) {
					cout << "NO" << endl;
					return 0;
				}
				for (int u = 0;u < v[j].size();++u) {
					if (v[j][u] == '?') {
						if (u < st) {
							v[j][u] = v[j - 1][u];
						}
						else {
							v[j][u] = '0';
						}
					}
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int j = 0;j < v.size();++j) {
		cout << v[j] << endl;
	}

	return 0;
}