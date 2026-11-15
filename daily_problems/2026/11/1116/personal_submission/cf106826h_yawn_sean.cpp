#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	auto query = [&] (int x) -> int {
		cout << "? " << x << endl;
		int v; cin >> v;
		return v;
	};

	auto answer = [&] (int x) -> void {
		cout << "! " << x << endl;
	};

	int start = query(2) ? 1 : 2;
	int l = 0, r = ((int)1e9 - start) / 2;

	while (l < r) {
		int mid = (l + r) / 2;
		int w = start + 2 * mid + 1;
		if (w % 2 == 0) w ++;

		if (query(w) == start % 2) r = mid;
		else l = mid + 1;
	}

	answer(start + 2 * l);

	return 0;
}