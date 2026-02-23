#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long op(long long x, long long y) {return max(x, y);}

long long e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i ++) cin >> ls[i] >> rs[i];

    vector<int> tmp;
    tmp.insert(tmp.end(), ls.begin(), ls.end());
    tmp.insert(tmp.end(), rs.begin(), rs.end());
    sort(tmp.begin(), tmp.end());

    atcoder::segtree<long long, op, e> seg(2 * n);

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return rs[i] < rs[j];});

    long long ans = -1e18;

    for (auto &idx: order) {
        int pl = lower_bound(tmp.begin(), tmp.end(), ls[idx]) - tmp.begin();
        int pr = lower_bound(tmp.begin(), tmp.end(), rs[idx]) - tmp.begin();

        long long val = seg.prod(0, pl + 1) + 1ll * rs[idx] * rs[idx] - 1ll * ls[idx] * ls[idx];
        seg.set(pr, max(seg.get(pr), val));

        ans = max(ans, 2 * val - 1ll * rs[idx] * rs[idx]);
    }

    cout << ans;

	return 0;
}