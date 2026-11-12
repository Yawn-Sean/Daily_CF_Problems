#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums(n), cnt(n + 1, 0);
	for (auto &x: nums) {
		cin >> x;
		if (x < n) cnt[x] ++;
	}

	int mex = 0;
	while (cnt[mex]) mex ++;

	if (mex && (*min_element(cnt.begin(), cnt.begin() + mex) == 1 || n % 2)) cout << "Dinny";
	else cout << "Tie";

	return 0;
}