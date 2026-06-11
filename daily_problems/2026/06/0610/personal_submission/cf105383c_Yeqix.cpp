#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

template <class T>
struct BIT {
	int n;
	vector<T> w;
	BIT(int n) {
		w.resize(n + 1);
		this->n = n;
	}

	void add(int x, T v) {
		assert(x > 0);
		while (x <= n) {
			w[x] += v;
			x += x & -x;
		}
	}

	T ask(int x) {
		T ans = 0;
		while (x) {
			ans += w[x];
			x -= x & -x;
		}
		return ans;
	}

	T ask(int l, int r) {
		return ask(r) - ask(l - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		p[b[i]] = a[i];
	}

	sort(b.begin() + 1, b.end(), [&](int x, int y) {
		return p[x] < p[y];
	});
	sort(a.begin() + 1, a.end());

	BIT<int> bt(n + 1);
	vector<i64> suf(n + 1);
	i64 inv = 0;
	for (int i = n; i >= 1; i--) {
		suf[i] = bt.ask(1, b[i]);
		inv += suf[i];
		bt.add(b[i], 1);
	}

	if (inv & 1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		inv >>= 1;
		for (int i = 1; i <= n; i++) {
			p[a[i]] = b[i];
		}

		for (int i = n; i >= 1; i--) {
			if (suf[i] > inv) {
				sort(a.begin() + i + 1, a.end(), [&](int x, int y) {
					return p[x] < p[y];
				});
				sort(b.begin() + i + 1, b.end());

				for (int j = i; inv; j ++) {
					if (b[j + 1] < b[j]) {
						inv--;
					}
					swap(a[j], a[j + 1]);
					swap(b[j], b[j + 1]);
				}
				break;
			}
			inv -= suf[i];
		}

		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			cout << b[i] << " ";
		}
	}
	return 0;
}
