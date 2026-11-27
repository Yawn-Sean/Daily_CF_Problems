#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int N = 1 << n;

	vector<long long> seg(N * 2);
	vector<int> lazy(N, -1);

	for (int i = N; i < N * 2; i ++) {
		int x; cin >> x;
		seg[i] = x;
	}

	for (int i = N - 1; i > 0; i --) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

	int q;
	cin >> q;

	auto bit_length = [&] (int x) -> int {
		return 32 - __builtin_clz(x);
	};

	auto pushdown = [&] (int pos) -> void {
		if (lazy[pos] == -1) return ;

		long long w = 1ll * lazy[pos] * (1 << n - bit_length(pos));

		seg[2 * pos] = w;
		seg[2 * pos + 1] = w;

		if (pos * 2 < N) {
			lazy[2 * pos] = lazy[pos];
			lazy[2 * pos + 1] = lazy[pos];
		}

		lazy[pos] = -1;
	};

	auto apply = [&] (int pos, int v) -> void {
		seg[pos] = 1ll * v * (1 << n - bit_length(pos) + 1);
		if (pos < N) lazy[pos] = v;
	};

	auto pushup = [&] (int pos) -> void {
		seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
	};

	while (q --) {
		int op;
		cin >> op;

		if (op == 1) {
			int l, r, k, v;
			cin >> l >> r >> k >> v;

			l += N;
			r += N + 1;

			int l0 = l, r0 = r;

			for (int i = n; i > 0; i --) {
				if (((l0 >> i) << i) != l0) pushdown((l0 >> i) ^ (k >> i));
				if (((r0 >> i) << i) != r0) pushdown(((r0 - 1) >> i) ^ (k >> i));
			}

			for (int i = 0; i <= n && l != r; i ++) {
				if (l & 1) apply(l ^ (k >> i), v), l ++;
				if (r & 1) r --, apply(r ^ (k >> i), v);
				l >>= 1;
				r >>= 1;
			}

			for (int i = 1; i <= n; i ++) {
				if (((l0 >> i) << i) != l0) pushup((l0 >> i) ^ (k >> i));
				if (((r0 >> i) << i) != r0) pushup(((r0 - 1) >> i) ^ (k >> i));
			}
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;

			l += N;
			r += N + 1;

			long long ans = 0;

			for (int i = n; i > 0; i --) {
				if (((l >> i) << i) != l) pushdown((l >> i) ^ (k >> i));
				if (((r >> i) << i) != r) pushdown(((r - 1) >> i) ^ (k >> i));
			}

			for (int i = 0; i <= n && l != r; i ++) {
				if (l & 1) ans += seg[l ^ (k >> i)], l ++;
				if (r & 1) r --, ans += seg[r ^ (k >> i)];
				l >>= 1;
				r >>= 1;
			}

			cout << ans << '\n';
		}
	}

	return 0;
}