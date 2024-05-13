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
using namespace std;


int main() {
	int n;cin >> n;
	map<int, int> l;
	vector<int> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
		l[a[i]] = i;
	}
	long long mod = 998244353;
	long long s = 1;
	int ed = 0;
	for (int i = 0;i < n;++i) {
		if (i <= ed) {
			ed = max(ed, l[a[i]]);
		}
		else {
			s *= 2;
			s %= mod;
			ed = l[a[i]];
		}
	}
	cout << s;

	return 0;
}