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
	int w, l;cin >> w >> l;

	vector<long long> v(w);
	for (int i = 1;i <= w - 1;++i) {
		cin >> v[i];
	}
	vector<long long> s(w);
	for (int i = 1;i <= l;++i) {
		s[i] = v[i];
	}
	int st = 1;
	for (int i = l + 1;i < w;++i) {
		long long cur = s[i];
		st = max(st, i-l);
		while (st < i) {
			if (s[i] + s[st] <= v[i]) {
				s[i] += s[st];
				s[st] = 0;
				st++;
			}
			else {
				s[st] -= v[i] - s[i];
				s[i] = v[i];
				break;
			}
		}

	}

	long long h = 0;
	for (int i = w - 1;i >= max(1,w - l);--i) {
		h += s[i];
	}
	cout << h;

	return 0;
}