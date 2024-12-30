#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;cin >> n;
	int r = 0;
	vector<pair<int, int>> v;
	for (int i = 1;i <= n;++i) {
		int c;cin >> c;
		if (c <= i) {
			int ck = i-c;
			v.push_back({ck, c});
		}
	}
	sort(v.begin(), v.end());
	vector<int> p(n + 1, 1e9);

	for (int i = 0;i < v.size();++i) {
		auto it = lower_bound(p.begin()+1, p.end(), v[i].second);
		r = max<int>(r, it-p.begin());
		*it = v[i].second;
	}
	cout << r;

	return 0;
}