#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

template <typename T>
struct Fenwick {
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> pos(n + 2), nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		pos[nums[i]] = i;
	}
	pos[0] = -1;
	pos[n + 1] = n;
	
	// 0....n
	Fenwick<int> fen(n + 1);
	for (int i = 0; i <= n; i++) {
		// 
		if (pos[i] > pos[i + 1]) {
			fen.add(i, 1);
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		int x, y;
		cin >> x >> y;
		if (op == 2) {
			//  val=x   val=y
			// val: (x-1, x x+1)   (y-1 y y+1)
			// val: (x-1, y x+1)   (y-1 x y+1)
			--x; --y;
			int val_x = nums[x], val_y = nums[y];
			
			set<int> check;
			for (int i = 0; i < 2; i++) {
				check.insert(val_x - i);
				check.insert(val_y - i);
			}
			
			for (auto& i: check) {
				if (pos[i] > pos[i + 1]) {
					fen.add(i, -1);
				}
			}
			
			swap(pos[val_x], pos[val_y]);
			swap(nums[x], nums[y]);
			
			for (auto& i: check) {
				if (pos[i] > pos[i + 1]) {
					fen.add(i, 1);
				}
			}
		} else {
			// val=x -> val=y
			cout << 1 + fen.rangeSum(x, y) << '\n';
		}
	}
	
	return 0;
}
