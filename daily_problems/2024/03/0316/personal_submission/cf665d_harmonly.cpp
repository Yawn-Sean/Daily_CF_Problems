#include <iostream>
#include <vector>

using namespace std;

std::vector<int> minp, primes;

void sieve(int n) {
	minp.assign(n + 1, 0);
	primes.clear();

	for (int i = 2; i <= n; ++i) {
		if (minp[i] == 0) {
			minp[i] = i;
			primes.push_back(i);
		}
		for (auto p : primes) {
			if (i * p > n) {
				break;
			}
			minp[i * p] = p;
			if (p == minp[i]) {
				break;
			}
		}
	}
}

bool isPrime(int x) {
	return minp[x] == x;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int one = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		one += a[i] == 1;
	}
	if (one > 0) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != 1 && isPrime(1 + a[i])) {
				cout << one + 1 << '\n';
				for (int i = 0; i < one; ++i) {
					cout << 1 << ' ';
				}
				cout << a[i] << '\n';
				return;
			}
		}
	}
	if (one > 1) {
		cout << one << '\n';
		for (int i = 0; i < one; ++i) {
			cout << 1 << " \n"[i == one - 1];
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (isPrime(a[i] + a[j])) {
				cout << 2 << '\n';
				cout << a[i] << ' ' << a[j] << '\n';
				return;
			}
		}
	}
	cout << 1 << '\n' << a[0] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(2e6 + 5);
	solve();
	return 0;
}
