#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

template <typename T>
struct Fenwick {
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	
	vector<int> nums1(n), nums2(n);
	Fenwick<int> f1(n), f2(n);
	
	/*
		第x天update
		
		sum(min(b, order)) i <= x - 1
		sum(min(a, order)) i >= x + k - 1
	*/
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			--x;
			
			int v;
			v = min(nums1[x] + y, b) - nums1[x];
			nums1[x] += v;
			f1.add(x, v); // preSum of min(b, v[i])
			
			v = min(nums2[x] + y, a) - nums2[x];
			nums2[x] += v;
			f2.add(x, v); // preSum of min(a, v[i])
		} else {
			int x;
			cin >> x;
			--x;
			cout << f1.sum(x) + f2.rangeSum(x + k, n) << '\n';
		}
	}
	return 0;
}
