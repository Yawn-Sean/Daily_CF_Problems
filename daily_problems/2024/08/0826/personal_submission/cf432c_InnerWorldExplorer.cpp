#include<bits/stdc++.h>
using namespace std;

const int N = (int)1E5 + 9;

int G[N];
int spf[N];
vector<int> primes;

void sieve() {
	for (int i = 2; i < N; i++) {
		if (spf[i] == 0) spf[i] = i, primes.push_back(i);
		int sz = primes.size();
		for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
			spf[i * primes[j]] = primes[j];
		}
	}
}

bool isPrime(int x) {
	return spf[x] == x;
}

void pre() {
	sieve();
	for (int i = 2; i <= N; i += 2) {
		for (auto p : primes) {
			if (isPrime(i - p)) {
				G[i] = p;
				break;
			}
		}
	}
}

int32_t main() {
	pre();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1), pos(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<pair<int, int>> ans;
	auto myswap = [&](int i, int j) {
		ans.push_back({i, j});
		swap(a[i], a[j]);
		swap(pos[a[i]], pos[a[j]]);
	};
	for (int i = 1; i <= n; i ++) {
		if (pos[i] != i) {
			int t = pos[i] - i;
			if (isPrime(t + 1)) {
				myswap(i, pos[i]);
			} else {
				if (t % 2) {
					myswap(i + G[t + 1], pos[i]);
					myswap(i + 1, i + G[t + 1]);
					myswap(i, i + 1);
				} else {
					myswap(i + G[t + 2] - 1, pos[i]);
					myswap(i, i + G[t + 2] - 1);
				}
			}
		}
	}
	cout << ans.size() << endl;
	for (auto [x, y] : ans) {
		cout << x << ' ' << y << endl;
	}
	return 0;
}
