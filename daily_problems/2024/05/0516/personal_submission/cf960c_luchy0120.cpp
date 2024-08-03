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
	long long x, d;cin >> x >> d;

	long long id = 1;
	auto create = [&]() {
		return id += d;
		};
	vector<long long> ans;
	for (int i = 30;i >= 1;--i) {
		if (x >> i & 1) {
			long long v1 = create();
			for (int j = 0;j < i;++j) {
				ans.push_back(v1);
			}
			v1 = create();
			ans.push_back(v1);
		}
	}
	if (x & 1) {
		ans.push_back(create());
	}

	cout << ans.size() << endl;
	for (int i = 0;i < ans.size(); ++i) {
		cout << ans[i] << " \n"[i==ans.size()-1];
	}





	return 0;
}