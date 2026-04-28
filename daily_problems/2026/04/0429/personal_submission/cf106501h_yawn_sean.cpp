#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long e() {return 0;}
long long op(long long x, long long y) {return x + y;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x, x -= k;

	vector<int> tags(n);
	for (auto &x: tags) cin >> x;

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] > nums[j];});

	vector<int> pos(n);
	for (int i = 0; i < n; i ++) pos[order[i]] = i;

	atcoder::segtree<long long, op, e> seg(n), seg_cnt(n);

	long long total = 0, cnt = 0;

	for (int i = 0; i < n; i ++) {
		if (tags[i] == 2) {
			if (nums[i] >= 0) {
				total += nums[i];
				cnt ++;
			}
			else {
				seg.set(pos[i], -nums[i]);
				seg_cnt.set(pos[i], 1);
			}
		}
	}

	int p = seg.max_right(0, [&] (long long v) {return v <= total;});
	long long ans = cnt + seg_cnt.prod(0, p);

	for (int i = 0; i < n; i ++) {
		if (tags[i] == 1) {
			if (nums[i] >= 0) {
				total += nums[i];
				cnt ++;
			}
			else {
				seg.set(pos[i], -nums[i]);
				seg_cnt.set(pos[i], 1);
			}
		}
		else {
			if (nums[i] >= 0) {
				total -= nums[i];
				cnt --;
			}
			else {
				seg.set(pos[i], 0);
				seg_cnt.set(pos[i], 0);
			}
		}

		p = seg.max_right(0, [&] (long long v) {return v <= total;});
		ans = max(ans, cnt + seg_cnt.prod(0, p));
	}

	cout << ans;

	return 0;
}