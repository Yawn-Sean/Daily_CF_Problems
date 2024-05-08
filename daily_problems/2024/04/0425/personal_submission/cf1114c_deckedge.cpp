#include <bits/stdc++.h>
using namespace std;

vector<int64_t> primes;
map<int, int> cnt;

int64_t solve(int64_t n, int64_t m) {
	int64_t res = 0;
	while (n) {
		res += n / m;
		n /= m;
	}
	return res;
}

void init(int64_t m) {
	int64_t tmp = m;
	for (int i = 2; (int64_t)i * i <= m; i++) {
		if (tmp % i == 0) {
			primes.emplace_back(i);
			while (tmp % i == 0) {
				tmp /= i;
				cnt[i]++;
			}
		}
	}
	if (tmp != 1) {
		primes.emplace_back(tmp);
		cnt[tmp]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int64_t n, m;
	cin >> n >> m;

    init(m);
	int i;

	int64_t mn = (1ll << 62);
	for (i = 0; i < primes.size(); i++) {
		mn = min(mn, solve(n, primes[i]) / cnt[primes[i]]);
	}

	cout << mn << '\n';
	return 0;
}