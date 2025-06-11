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

	vector<long long> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

	for (int i = 0;i < n;++i) {
		q.push({a[i],i});
	}
	set<pair<int, long long>> st;
	while (q.size() >= 2) {
		auto c1 = q.top(); q.pop();
		auto c2 = q.top(); q.pop();
		if (c1.first == c2.first) {
			q.push({c1.first * 2L, max(c1.second, c2.second)});
		}
		else {
			st.insert({ c1.second,c1.first });
			q.push(c2);
		}
	}
	if (q.size() > 0) {
		auto c1 = q.top(); q.pop();
		st.insert({ c1.second,c1.first });
	}
	cout << st.size() << endl;
	for (auto c : st) {
		cout << c.second << " ";
	}






	return 0;
}